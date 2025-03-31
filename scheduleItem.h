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
    string instructor;
    int units;
    int totEnrl;
    int capEnrl;

    
    SchedItem(string sub = "", string cat = "", string sec = "", string com = "", string ses = "", string ins = "", int uni = 0, int totE = 0, int capE = 0) :
        subject(sub), catalog(cat), section(sec), component(com), session(ses), instructor(ins), units(uni), totEnrl(totE), capEnrl(capE) {
    };
};

class scheduleItem
{
public:

    scheduleItem()
    {
        sItem = SchedItem();
    }

    scheduleItem(string sub, string cat, string sec, string com, string ses, string ins, int uni, int totE, int capE)
    {
        sItem = SchedItem(sub, cat, sec, com, ses, ins, uni, totE, capE);
    }
    
    void getScheduleItem(SchedItem& item) {
        item = sItem;
    };

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