#ifndef ZLASER_H
#define ZLASER_H

#include "windows.h"

#define DLLEXPORT __declspec(dllexport)

#define READ_BUFFER_SIZE 256

#define LASER_OFF        0
#define LASER_ON         1

#define CMD_IDENTIFY     "identify\n"
#define CMD_TEST         "identify\n"
#define CMD_SET          "set %s %d\n"

#define MSG_OK           "OK\r\n"

extern "C"
{
	DLLEXPORT bool zl_device_open(char *port, int &hComm);
	DLLEXPORT bool zl_device_close(int device);
	DLLEXPORT bool zl_device_read(int hComm, char *buff, int size, int &sizeRead);
	DLLEXPORT bool zl_device_write(int hComm, char *buff, int size, int &sizeWritten);
	DLLEXPORT bool zl_device_reset(int hComm);
	DLLEXPORT bool zl_device_test(int hComm);
	DLLEXPORT bool zl_device_set(int hComm, char *ledName, int state);
	DLLEXPORT int  zl_device_get(int hComm, char *ledName, int state);
}

#endif