#include <iostream>
#include <cassert>
#include "zlaser.h"
#include "windows.h"


extern "C"
{
	char _ID[READ_BUFFER_SIZE - 1];

	DLLEXPORT bool zl_device_open(char *port, int &hComm) {
		printf("zl_device_open(): port=%s\n", port);
		hComm = 9999;
		return true;
	}


	DLLEXPORT bool zl_device_read(int hComm, char *buff, int size, int &sizeRead) {
		printf("zl_device_read(): size=%d\n", size);
		buff[0] = 'H';
		buff[1] = 'e';
		buff[2] = 'l';
		buff[3] = 'l';
		buff[4] = 'o';
		buff[5] = 0;
		sizeRead = 6;
		return true;
	}

	DLLEXPORT bool zl_device_convert_buffer(unsigned char *buff, int size) {
		printf("zl_device_convert_buffer(): size=%d\n", size);
		for (int i = 0; i < size; i++) {
			buff[i] = 121;
		}
		return true;
	}

	DLLEXPORT bool zl_device_write(int hComm, char *buff, int size, int &sizeWritten) {
		printf("zl_device_write()\n");
		return true;
	}


	DLLEXPORT bool zl_device_set(int hComm, char *ledName, int state) {
		printf("zl_device_set()\n");
		return true;
	}


	DLLEXPORT int zl_device_get(int hComm, char *ledName, int state) {
		printf("zl_device_get()\n");
		return 0;
	}


	DLLEXPORT bool zl_device_test(int hComm) {
		printf("zl_device_test()\n");
		return true;
	}


	DLLEXPORT bool zl_device_reset(int hComm) {
		printf("zl_device_reset()\n");
		return true;
	}


	DLLEXPORT bool zl_device_close(int hComm) {
		printf("zl_device_id(): comm%d\n", hComm);
		return true;
	}

}