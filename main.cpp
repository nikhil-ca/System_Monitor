//main.cpp

#include "system_monitor.h"
#include <iostream>
#include <unistd.h>

int main() {
	//Create an instance of SystemMonitor
	SystemMonitor monitor;
	
	//Continuosly monitor system resources
	while(true) {
		double cpu_usage = monitor.get_cpu_usage();
		double memory_usage = monitor.get_memory_usage();
		
		std::cout <<"CPU Usage:" <<cpu_usage<< "%" <<std::endl;
		std::cout <<"Memory Usage:"<<memory_usage<<"%"<<std::endl;
		
		//Sleep for some time before checking again
		sleep(1);
	}
	
	return 0;
}
