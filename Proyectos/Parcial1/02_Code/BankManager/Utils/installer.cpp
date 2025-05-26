#include <wx/wx.h>
#include <wx/stattext.h>
#include <fstream>
#include <string>
#include <filesystem>

class InstallerFrame : public wxFrame {
public:
    InstallerFrame() : wxFrame(nullptr, wxID_ANY, "Asistente de Instalacion", wxDefaultPosition, wxSize(400, 250)) {
        panel = new wxPanel(this);

        new wxStaticText(panel, wxID_ANY, "Ingrese su clave de producto:", wxPoint(20, 30));
        keyInput = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(20, 55), wxSize(350, 25));

        installButton = new wxButton(panel, wxID_ANY, "Instalar", wxPoint(20, 100), wxSize(100, 30));
        installButton->Bind(wxEVT_BUTTON, &InstallerFrame::OnInstallClicked, this);

        statusLabel = new wxStaticText(panel, wxID_ANY, "", wxPoint(20, 150), wxSize(350, 30));
    }

private:
    wxPanel* panel;
    wxTextCtrl* keyInput;
    wxButton* installButton;
    wxStaticText* statusLabel;

    std::string trim(const std::string& s) {
        size_t start = s.find_first_not_of(" \t\r\n");
        size_t end = s.find_last_not_of(" \t\r\n");
        return (start == std::string::npos) ? "" : s.substr(start, end - start + 1);
    }

    bool estaEnArchivo(const std::string& archivo, const std::string& clave) {
        std::ifstream in(archivo);
        std::string linea;
        while (getline(in, linea)) {
            if (trim(linea) == trim(clave)) return true;
        }
        return false;
    }

    void registrarClaveUsada(const std::string& clave, const std::string& archivo) {
        std::ofstream out(archivo, std::ios::app);
        out << clave << std::endl;
    }

    void copiarArchivo(const std::string& origen, const std::string& destino) {
        std::filesystem::create_directories(std::filesystem::path(destino).parent_path());
        std::filesystem::copy_file(origen, destino, std::filesystem::copy_options::overwrite_existing);
    }

    void OnInstallClicked(wxCommandEvent& event) {
        std::string clave = keyInput->GetValue().ToStdString();

        if (!estaEnArchivo("claves_validas.txt", clave)) {
            statusLabel->SetLabel("Clave invalida");
            return;
        }

        if (estaEnArchivo("claves_usadas.txt", clave)) {
            statusLabel->SetLabel("Clave ya usada");
            return;
        }

        try {
            copiarArchivo("../mi_banco.exe", std::string(std::getenv("USERPROFILE")) + "/Desktop/mi_banco.exe");
            registrarClaveUsada(clave, "claves_usadas.txt");
            statusLabel->SetLabel("Instalacion completada");
        } catch (...) {
            statusLabel->SetLabel("Error al copiar archivos ");
        }
    }
};

class InstallerApp : public wxApp {
public:
    bool OnInit() override {
        InstallerFrame* frame = new InstallerFrame();
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(InstallerApp);
