#include <iostream>
#include <unistd.h>

int main() {
  while (true) {
    double cpu_usage = 0;
    double memory_usage = 0;
    std::cout <<"CPU Usage: " << cpu_usage << "%" <<std::endl;
    std::cout<<"Memory Usage: " << memory_usage << "%" <<std::endl;
    std::cout<<"-------------------------------"<< std::endl;
    sleep(1);
  }
  
  return 0;
}
