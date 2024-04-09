#ifndef SCHEDITEM_H
#define SCHEDITEM_H

#include <string>
#include <iostream>
#include <functional>
using namespace std;

class scheduleItem
{
  public:
  scheduleItem(string="", string="", string="", string="", string="", string="", int=0, int=0, int=0);
  void getscheduleItem(string &sub, string &cat, string &sec, string &com, string &ses, string &ins, int &uni, int &totE, int &capE);

    void print();
    void printHeader();

    bool operator==(const scheduleItem& operand2) const;
    bool operator!=(const scheduleItem& operand2) const;
    bool operator>=(const scheduleItem& operand2) const;

    string getSubject() const { return subject; }
    string getCatalog() const { return catalog; }
    string getSection() const { return section; }
    string getComponent(){ return component; }
    string getSession(){ return session; }
    string getInstructor(){ return instructor; }
    int getUnits(){ return units; }
    int getTotEnrl(){ return totEnrl; }
    int getCapEnrol(){ return capEnrl; }

  private:
    string subject;
    string catalog;
    string section;
    string component;
    string session;
    string instructor;
    int units;
    int totEnrl;
    int capEnrl;

};

#endif