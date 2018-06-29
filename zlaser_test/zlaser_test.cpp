#include <iostream>
#include <cassert>
#include "../zlaser/zlaser.h"

int main() {
	int h;	
	BOOL status;
	char portname[128];
	
	std::cout << "Z-Laser control testing:" << std::endl;
	
	int port = 12;
	sprintf_s(portname, "\\\\.\\COM%d", port);
	
	zl_device_open(portname, h);

	if (h == 0) {
		std::cerr << "Unable to connect laser device on COM" << port << std::endl;
	}	
	
	status = zl_device_test(h); 
	std::cout << "done" << std::endl;

	status = zl_device_reset(h);

	std::cout << "Laser on";
	status = zl_device_set(h, "LASER_SWITCH", LASER_ON);
	Sleep(1000);

	for (int i = 1; i <= 10; i++) {
		std::cout << "Laser intensity " << i << std::endl;
		status = zl_device_set(h, "LASER_INTENSITY", i * 10);
		Sleep(3000);
	}
	
	std::cout << "Laser off";
	status = zl_device_set(h, "LASER_SWITCH", LASER_OFF);
	
	zl_device_reset(h);

	zl_device_close(h);
}