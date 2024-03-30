//main.cpp

#include "system_monitor.h"
#include <iostream>
#include <unistd.h>

int main() {
  while (true) {
    double cpu_usage = get_cpu_usage();
    double memory_usage = get_memory_usage();
    std::cout <<"CPU Usage: " << cpu_usage << "%" <<std::endl;
    std::cout<<"Memory Usage: " << memory_usage << "%" <<std::endl;
    std::cout<<"-------------------------------"<< std::endl;
    sleep(1);
  }
  
  return 0;
}
