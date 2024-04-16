// system_monitor.cpp

#include "system_monitor.h"
#include <fstream>
#include <sstream>
#include <unistd.h>



double SystemMonitor::get_cpu_usage() {
    double cpu_usage = 0.0;
    std::string line;
    std::ifstream file("/proc/stat");
    if(file.is_open()) {
        getline(file, line);
        std::istringstream iss(line);
        std::string cpu;
        iss >> cpu;
        if (cpu == "cpu"){
            int user, nice, system, idle, iowait, irq, softirq;
            iss >>user >> nice >> system >> idle >>iowait >> irq >> softirq;
            int total_idle = idle + iowait;
            int total_non_idle = user + nice + system +irq + softirq;
            int total = total_idle + total_non_idle;
            cpu_usage = (1.0 - (total_idle*1.0/total))*100;
        }
    }
    file.close();
    return cpu_usage;
}

double SystemMonitor::get_memory_usage(){
    double memory_usage = 0.0;
    std::string line;
    std::ifstream file("/proc/meminfo");
    if (file.is_open()){
        while(getline(file,line)){
            std::istringstream iss(line);
            std::string key;
            double value;
            if(iss >> key >> value) {
                if (key == "MemTotal:"){
                    double total_memory = value;
                    if (getline(file,line)) {
                        std::istringstream iss(line);
                        if(iss >> key >> value && key == "MemAvailable:"){
                            double available_memory = value;
                            memory_usage = ((total_memory - available_memory)/total_memory) * 100.0;
                            break;
                        }
                    }
                }
            }
        }
    }
    file.close();
    return memory_usage;
}
