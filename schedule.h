#ifndef SCHED_H
#define SCHED_H

#include <iostream>
#include<fstream>
#include "HashTable.h"
#include "scheduleItem.h"

class schedule
{
private:
    HashTable<string, scheduleItem> semesterSchedule;

public:
    schedule(int maxSize);
    void addEntry(scheduleItem&);
    void print();
    void initSchedule(ifstream&);
    void findSub(string target);
    void findSubCat(string, string);
    void findInstructor(string);
    string getKey(scheduleItem&);
    void setHashFunction(std::function<size_t(const std::string&)> hashFunc);

    size_t getTableSize();
    void statistics();

    class ScheduleIterator
    {
    private:
        int index = 0;
        int maxIndex;
        int maxItems = 0;
        vector<scheduleItem> current;

    public:
        ScheduleIterator(vector<scheduleItem> first, int max) : current(first), maxIndex(max) {};

        vector<scheduleItem> &operator*()
        {
            /*vector<SchedItem> items(current.size());
            for (int i = 0; i < current.size(); i++)
            {
                SchedItem item;
                current[i].getScheduleItem(item);
                items[i] = item;
            }*/

            return current;
        }

        bool operator!=(const ScheduleIterator& other) const {
            return current.size() > 0;
        }

        ScheduleIterator& operator++()
        {
            do
            {
                index++;
                if (index == maxIndex)
                {
                    current.resize(0);
                    break;
                }
                else
                {
                    current = semesterSchedule.getByIndex(index);
                }
            } while (current.size() == 0);
            return *this;
        }
    };

    ScheduleIterator begin() 
    {
        int maxIndex = semesterSchedule.getSize();
        vector<scheduleItem> first = semesterSchedule.getByIndex(0);
        return ScheduleIterator(first, maxIndex);
    }
    ScheduleIterator end() 
    {  
        vector<scheduleItem> empty(0);
        return empty;
    }

};


#endif