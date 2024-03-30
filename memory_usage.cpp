#include <fstream>
#include <sstream>
#include <string>

double get_memory_usage(){
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
