#include "BackupManager.h"
#include "CesarCifration.h"
#include <fstream>
#include <sstream>
#include <ctime>
#include <iostream>

bool BackupManager::makeBackup(const std::string& original, const std::string& backup, int key) {
    CesarCifration cesar(key);

    cesar.decryptFile(original);

    if (!copyFile(original, backup)) {
        cesar.encryptFile(original);
        return false;
    }

    cesar.encryptFile(backup);
    cesar.encryptFile(original);

    return true;
}

bool BackupManager::restoreBackup(const std::string& backup, const std::string& original, int key) {
    CesarCifration cesar(key);

    std::cout << "[DEBUG] Descifrando backup: " << backup << std::endl;
    bool decifrado = cesar.decryptFile(backup);
    if (!decifrado) {
        std::cout << "[DEBUG] Error al descifrar el backup.\n";
        return false;
    }

    std::ifstream checkBackup(backup, std::ios::binary | std::ios::ate);
    std::streamsize backupSize = checkBackup.tellg();
    std::cout << "[DEBUG] Tamanio del backup tras descifrar: " << backupSize << " bytes\n";
    checkBackup.close();

    std::cout << "[DEBUG] Copiando backup sobre original...\n";
    bool copia = copyFile(backup, original);
    if (!copia) {
        cesar.encryptFile(backup);
        std::cout << "[DEBUG] Error al copiar el backup sobre el original.\n";
        return false;
    }

    std::ifstream checkOriginal(original, std::ios::binary | std::ios::ate);
    std::streamsize origSize = checkOriginal.tellg();
    std::cout << "[DEBUG] Tamanio del archivo original tras copiar: " << origSize << " bytes\n";
    checkOriginal.close();

    cesar.encryptFile(backup);
    cesar.encryptFile(original);

    std::cout << "[DEBUG] Backup restaurado y cifrado.\n";
    return true;
}

std::string BackupManager::getTimestampedBackupName(const std::string& prefix, const std::string& ext) {
    time_t now = time(nullptr);
    tm* local = localtime(&now);
    std::ostringstream oss;
    oss << prefix
        << (local->tm_year + 1900)
        << ((local->tm_mon + 1) < 10 ? "0" : "") << (local->tm_mon + 1)
        << (local->tm_mday < 10 ? "0" : "") << local->tm_mday << "_"
        << (local->tm_hour < 10 ? "0" : "") << local->tm_hour
        << (local->tm_min < 10 ? "0" : "") << local->tm_min
        << (local->tm_sec < 10 ? "0" : "") << local->tm_sec
        << ext;
    return oss.str();
}

bool BackupManager::copyFile(const std::string& src, const std::string& dest) {
    std::ifstream in(src, std::ios::binary);
    std::ofstream out(dest, std::ios::binary | std::ios::trunc);
    if (!in || !out) return false;
    out << in.rdbuf();
    return in && out;
}
