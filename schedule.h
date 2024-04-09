#ifndef SCHED_H
#define SCHED_H

#include <iostream>
#include<fstream>
#include "HashTable.h"
#include "scheduleItem.h"

class schedule
{
  public:
    schedule(int maxSize);
    void addEntry(scheduleItem &);
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

    HashTable<string, scheduleItem> semesterSchedule;
};


#endif