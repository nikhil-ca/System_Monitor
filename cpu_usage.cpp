// cpu_usage.cpp

#include <fstream>
#include <sstream>
#include <string>

double get_cpu_usage() {
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
