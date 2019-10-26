#include <fstream>
#include <cstring>
#include <sstream>
#include <iostream>

#include "backup.h"

Backup::Backup(std::string fileBlock)
{
    fBlock = fileBlock;
}

Backup::~Backup()
{

}

void Backup::getBackup()
{
    if(fBlock == "loader")
    {
        std::cout << "\nOpen...";

        command = "/dev/block/mmcblk0boot0";
        source = "/sdcard/MotoBackup/loader.bin";

        std::ifstream block(command, std::ifstream::binary);
        std::ofstream bkp(source, std::ofstream::binary);

        std::cout << "\nWrite...";
        
        bkp << block.rdbuf();

        block.close();
        bkp.close();

        std::cout << "\nOk..." << std::endl << "File: /sdcard/MotoBackup/loader.bin" << std::endl;
    }
    else if(fBlock == "config")
    {
    	system("su -c mkdir /sdcard/MotoBackup");
    	std::cout << "\nComplete" << std::endl;
    }
    else if(fBlock == "help")
    {
        std::cout << "Utility Backup special created for device Motorola Moto C 4G(Namath)." << std::endl;

        std::cout << "Example: backup loader" << std::endl;

        std::cout << "Keys:" << std::endl
                  << "config - create dir MotoBackup" << std::endl
                  << "boot - backup boot.img" << std::endl
                  << "efuse - backup efues.img" << std::endl
                  << "expdb - backup expdb.img" << std::endl
                  << "flashinfo - backup flashinfo.img" << std::endl
                  << "frp - backup frp.img" << std::endl
                  << "keystore - backup keystore.img" << std::endl
                  << "lk - backup lk.img" << std::endl
                  << "logo - backup logo.img" << std::endl
                  << "metadata - backup metadata.img" << std::endl
                  << "nvdata - backup nvdata.img" << std::endl
                  << "nvram - backup nvram.img" << std::endl
                  << "oemkeystore - backup oemkeystore.img" << std::endl
                  << "para - backup para.img" << std::endl
                  << "proinfo - backup proinfo.img" << std::endl
                  << "protect1 - backup protect1.img" << std::endl
                  << "protect2 - backup protect2.img" << std::endl
                  << "recovery - backup recovery.img" << std::endl
                  << "seccfg - backup seccfg.img" << std::endl
                  << "secro - backup secro.img" << std::endl
                  << "system - backup system.img" << std::endl
                  << "tee1 - backup tee1.img" << std::endl
                  << "tee2 - backup tee2.img" << std::endl;

    }
    else
    {
            std::cout << "\nOpen...";

            command = "/dev/block/platform/mtk-msdc.0/by-name/" + fBlock;
            source = "/sdcard/MotoBackup/" + fBlock + ".img";
            
            std::ifstream block(command, std::ifstream::binary);
            std::ofstream bkp(source, std::ofstream::binary);

            std::cout << "\nWrite...";

            bkp << block.rdbuf();

            block.close();
            bkp.close();

            std::cout << "\nOk..." << std::endl << "File: /sdcard/MotoBackup/" << fBlock << ".img" << std::endl;
    }
}
