#ifndef BACKUP_H
#define BACKUP_H

#include <iostream>

class Backup
{
private:
    std::string fBlock;

    std::string command;
    std::string source;

public:
    Backup(char* fileBlock);

    ~Backup();

    void getBackup();
};

#endif // BACKUP_H
