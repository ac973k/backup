#include <iostream>
#include <cstring>

#include "backup.h"

int main(int argc, char** argv)
{
    if(argc <= 1)
    {
        std::cerr << "Error! Example: \n" << "backup boot" << std::endl << "Used backup help" << std::endl;
    }

    Backup bkp(argv[1]);
    bkp.getBackup();

    return 0;
}
