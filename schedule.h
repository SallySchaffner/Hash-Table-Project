#ifndef SCHED_H
#define SCHED_H

#include <iostream>
#include<fstream>
#include <unordered_map>
#include <utility>
#include "scheduleItem.h"

struct CustomStringHash {
    std::size_t operator()(const std::string& s) const {
        std::size_t hash = 0;
        for (char c : s) {
            hash = hash * 31 + c;
        }
        return hash;
    }
};

class schedule
{
  public:  
    schedule(int maxSize);
    void addEntry(string, scheduleItem);
    void print();
    void initSchedule(ifstream&);
    void findSub(string target);
    void findSubCat(string, string);
    void findInstructor(string);
    string getKey(scheduleItem &);
    void statistics();

  private:

    unordered_map<string, scheduleItem, CustomStringHash> semesterSchedule;
    vector<string> getFields(string line);
};


#endif