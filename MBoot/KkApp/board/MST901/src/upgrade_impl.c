#include <common.h>
#include <usb.h>
#include <malloc.h>
#include <stdio.h> 

#include <kk_board.h>
#include <upgrade_impl.h>
#include <upgrade_usb_util.h>
#include <MsUpgradeUtility.h>
int LoadBootloaderUpgradeScript2Dram(char* upgradeFile, char** script_buffer)
{
	if(upgradeFile == NULL)
		upgradeFile = DEFAULT_MBOOT_BIN_PATH;
	setUpgradeMode(EN_UPDATE_MODE_USB);
	return LoadUpgradeScript2Dram(upgradeFile, script_buffer);
}


int LoadUpgradeScript2Dram(char *upgradeFile, char ** script_buffer)
{
    char buffer[CONFIG_SYS_CBSIZE] = "\0";
    char *tmp_script_buf = (char*)UPGRADE_BUFFER_ADDR;
    int partition = 0;
    int device = 0;

	if(upgradeFile == NULL)
		upgradeFile = DEFAULT_USB_UPGRADE_BIN_PATH;
    if(kk_check_file_partition(tmp_script_buf, upgradeFile,&device,&partition)!=0)
    {
        printf("fail : no file in usb\n");
        return -1;
    }
    else
    {
    	 printf("set device and partition!!\n");
    	setUpgradeDevice(device);
	setUpgradePartition(partition);	
    }

    //Load Script
    snprintf(buffer, CONFIG_SYS_CBSIZE, "fatload usb %d:%d  %X %s %X",device, partition, UPGRADE_BUFFER_ADDR, upgradeFile, SCRIPT_SIZE);
    if(-1 == run_command(buffer, 0))
    {
        printf("Error: cmd: %s\n",buffer);
        return -1;
    }
    /*Check script file is ciphertext or not(start)*/
    *script_buffer=(char *)UPGRADE_BUFFER_ADDR;
    snprintf(buffer, CONFIG_SYS_CBSIZE, "setenv UpgradeImage %s", upgradeFile);
    if(-1 == run_command(buffer, 0))
    {
        printf("Error: cmd: %s\n",buffer);
        return -1;
    }
    /*
        //check script crc
        if(check_script_crc(upgradeFile)==-1)
        {
            printf("Error: check_script_crc Fail !!\n");
            return -1;
        }
      */
     return 0;
}

int usb_stop_all(void)
{
	int i = 0;
	for(i=0; i < MAX_DEVICE; ++i) {
		usb_stop(i);
	}
	return 0;
}

int usb_stor_scan_all(int* portId)
{
	int i = 0;
	int ret = -1;
	for(i=0; i < MAX_DEVICE; ++i) {
		if(usb_init(i) == 0)
		{
			if(usb_stor_scan(1) == 0)
			{
				if(portId != NULL)
					*portId = i;
				return 0;
			}
		}
	}
	return -1;
}

