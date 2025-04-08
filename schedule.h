#ifndef SCHED_H
#define SCHED_H

#include <iostream>
#include<fstream>
#include <unordered_map>
#include <utility>
#include "scheduleItem.h"

struct CustomStringHash {
    size_t operator()(const string& s) const {

        // std::hash
        hash<string> str_hash;
        return str_hash(s);
    }
};

class schedule
{
public:
    schedule(int size);;
    void addEntry(string, scheduleItem);
    void print();
    void initSchedule(ifstream&);
    void findSub(string target);
    void findSubCat(string, string);
    void findInstructor(string);
    string getKey(scheduleItem&);
    void statistics();

private:
    unordered_map<string, scheduleItem, CustomStringHash> semesterSchedule;
    vector<string> getFields(string line);
    int numEntries = 0;  // Number of rows in spreadsheet
};


#endif