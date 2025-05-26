#pragma once

#include <string>

class BackupManager {
public:
    static bool makeBackup(const std::string& original, const std::string& backup, int key = 3);
    static bool restoreBackup(const std::string& backup, const std::string& original, int key = 3);
    static std::string getTimestampedBackupName(const std::string& prefix = "users_backup_", const std::string& ext = ".dat");

private:
    static bool copyFile(const std::string& src, const std::string& dest);
};
