// desierto_busqueda_oasis.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// -----------------------------
// QuickSort
// -----------------------------
class QuickSort {
public:
    void ordenar(vector<int>& arr) {
        quicksort(arr, 0, arr.size() - 1);
    }

private:
    void quicksort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(arr, low, high);
            quicksort(arr, low, pivotIndex - 1);
            quicksort(arr, pivotIndex + 1, high);
        }
    }

    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; ++j) {
            if (arr[j] <= pivot) {
                ++i;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }
};

// -----------------------------
// BusquedaBinaria
// -----------------------------
class BusquedaBinaria {
public:
    int buscarCercano(const vector<int>& arr, int objetivo, int izq = 0, int der = -1) {
        if (arr.empty()) return -1;
        if (der == -1) der = arr.size() - 1;

        while (izq <= der) {
            int mid = izq + (der - izq) / 2;
            if (arr[mid] == objetivo) {
                return arr[mid];
            } else if (arr[mid] < objetivo) {
                izq = mid + 1;
            } else {
                der = mid - 1;
            }
        }

        int mejor = arr[min(izq, (int)arr.size() - 1)];
        if (der >= 0 && izq < arr.size()) {
            if (abs(arr[der] - objetivo) < abs(arr[izq] - objetivo)) {
                mejor = arr[der];
            }
        }
        return mejor;
    }
};

// -----------------------------
// Persona
// -----------------------------
class Persona {
private:
    vector<int> posiciones; // tamaño 3
    int mediana;
    int distanciaTotal;
    QuickSort quickSort;

public:
    Persona(const vector<int>& pos) : posiciones(pos), mediana(0), distanciaTotal(0) {}

    void EncontrarMediana() {
        quickSort.ordenar(posiciones);
        mediana = posiciones[1];
    }

    int EncontrarDistanciaMinima() {
        distanciaTotal = 0;
        for (int val : posiciones) {
            distanciaTotal += abs(mediana - val);
        }
        return distanciaTotal;
    }

    int getMediana() const { return mediana; }
    int getDistanciaTotal() const { return distanciaTotal; }
};

// -----------------------------
// Oasis
// -----------------------------
class Oasis {
private:
    vector<int> posiciones;
    QuickSort quickSort;
    BusquedaBinaria buscador;

public:
    Oasis(const vector<int>& pos) : posiciones(pos) {}

    void ordenar() {
        quickSort.ordenar(posiciones);
    }

    pair<int, int> encontrarMasCercano(int punto) {
        int cercano = buscador.buscarCercano(posiciones, punto);
        int distancia = abs(punto - cercano);
        return {cercano, distancia};
    }
};

// -----------------------------
// main (ejemplo de uso)
// -----------------------------
int main() {
    Persona grupo({-5, 3, 10});
    grupo.EncontrarMediana();
    grupo.EncontrarDistanciaMinima();

    cout << "Punto de encuentro: " << grupo.getMediana() << endl;
    cout << "Distancia total: " << grupo.getDistanciaTotal() << endl;

    Oasis oasis({-6, 0, 9, 15});
    oasis.ordenar();
    auto resultado = oasis.encontrarMasCercano(grupo.getMediana());

    cout << "Oasis más cercano: " << resultado.first << " a distancia " << resultado.second << endl;

    return 0;
}
