#ifndef SCHED_H
#define SCHED_H

#include <iostream>
#include<fstream>
#include <unordered_map>
#include <utility>
#include "scheduleItem.h"

class schedule
{
  public:  
    schedule(int maxSize);
    void addEntry(string, scheduleItem &);
    void print();
    void initSchedule(ifstream&);
    void findSub(string target);
    void findSubCat(string, string);
    void findInstructor(string);
    string getKey(scheduleItem &);
    void setHashFunction(std::function<size_t(const std::string&)> hashFunc);

    size_t getTableSize();
    void statistics();

  private:

    unordered_map<string, scheduleItem> semesterSchedule;
    vector<string> getFields(string line);
};


#endif