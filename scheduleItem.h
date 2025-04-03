#ifndef SCHEDITEM_H
#define SCHEDITEM_H

#include <string>
#include <iostream>
#include <functional>
using namespace std;

struct SchedItem
{
    string subject;
    string catalog;
    string section;
    string component;
    string session;
    int units;
    int totEnrl;
    int capEnrl;
    string instructor;

    
    SchedItem(string sub = "", string cat = "", string sec = "", string com = "", string ses = "", int uni = 0, int totE = 0, int capE = 0, string ins = "") :
        subject(sub), catalog(cat), section(sec), component(com), session(ses), units(uni), totEnrl(totE), capEnrl(capE), instructor(ins) {};
};

class scheduleItem
{
public:

    scheduleItem()
    {
        sItem = SchedItem();
    }

    scheduleItem(string sub, string cat, string sec, string com, string ses, int uni, int totE, int capE, string ins)
    {
        SchedItem sItem = SchedItem(sub, cat, sec, com, ses, uni, totE, capE, ins);
    }
    
    SchedItem& getScheduleItem() { return sItem; }

    string makeKey();
    
    void print();
    void printHeader();

    bool operator==(const SchedItem& operand2) const;
    bool operator!=(const SchedItem& operand2) const;
    bool operator>(const SchedItem& operand2) const;

private:
    SchedItem sItem;
};

#endif