#include <iostream>
#include <iomanip>
#include "scheduleItem.h"

using namespace std;

scheduleItem::scheduleItem(string sub, string cat, string sec, string com, string ses, string ins, int uni, int totE, int capE)
{
    subject = sub;
    catalog = cat;
    section = sec;
    component = com;
    session = ses;
    instructor = ins;
    units = uni;
    totEnrl = totE;
    capEnrl = capE;
}

void scheduleItem::getscheduleItem(string &sub, string &cat, string &sec, string &com, string &ses, string &ins, int &uni, int &totE, int &capE)
{
  sub = subject;
  catalog = cat;
  section = sec;
  component = com;
  session = ses;
  instructor = ins;
  units = uni;
  totEnrl = totE;
  capEnrl = capE;
}

void scheduleItem::print()
{
  cout << setw(3) << subject << setw(9) << catalog << setw(10) << section;
  cout << setw(10) << component << setw(11) << session;
  cout << setw(8) << units << setw(8) << totEnrl << setw(9) << capEnrl;
  cout << "     " << instructor << endl; 
}

void scheduleItem::printHeader()
{
  cout << "Subject  Catalog  Section  Component  Session  Units  TotEnrl  CapEnrl  Instructor" << endl;
}

bool scheduleItem::operator==(const scheduleItem& operand2) const
{
    string itemName1 = subject + '_' + section + '_' + session;
    string itemName2 = operand2.subject + '_' + operand2.section + '_' + operand2.session;
    return (itemName1 == itemName2);
}

bool scheduleItem::operator!=(const scheduleItem& operand2) const
{
    string itemName1 = subject + '_' + section + '_' + session;
    string itemName2 = operand2.subject + '_' + operand2.section + '_' + operand2.session;
    return (itemName1 != itemName2);
}

bool scheduleItem::operator>=(const scheduleItem& operand2) const
{
    string itemName1 = subject + '_' + section + '_' + session;
    string itemName2 = operand2.subject + '_' + operand2.section + '_' + operand2.session;
    return (itemName1 >= itemName2);
}