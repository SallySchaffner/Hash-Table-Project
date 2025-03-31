#include <iostream>
#include <iomanip>
#include "scheduleItem.h"

using namespace std;

string scheduleItem::makeKey()
{
    string key = sItem.subject + "_" + sItem.catalog + "_" + sItem.section;
    return key;
}

void scheduleItem::print()
{
  cout << setw(3) << sItem.subject << setw(9) << sItem.catalog << setw(10) << sItem.section;
  cout << setw(10) << sItem.component << setw(11) << sItem.session;
  cout << setw(8) << sItem.units << setw(8) << sItem.totEnrl << setw(9) << sItem.capEnrl;
  cout << "     " << sItem.instructor << endl;
}

void scheduleItem::printHeader()
{
  cout << "Subject  Catalog  Section  Component  Session  Units  TotEnrl  CapEnrl  Instructor" << endl;
}

bool scheduleItem::operator==(const SchedItem& operand2) const
{
    string itemName1 = sItem.subject + '_' + sItem.section + '_' + sItem.session;
    string itemName2 = operand2.subject + '_' + operand2.section + '_' + operand2.session;
    return (itemName1 == itemName2);
}

bool scheduleItem::operator!=(const SchedItem& operand2) const
{
    string itemName1 = sItem.subject + '_' + sItem.section + '_' + sItem.session;
    string itemName2 = operand2.subject + '_' + operand2.section + '_' + operand2.session;
    return (itemName1 != itemName2);
}

bool scheduleItem::operator>(const SchedItem& operand2) const
{
    string itemName1 = sItem.subject + '_' + sItem.section + '_' + sItem.session;
    string itemName2 = operand2.subject + '_' + operand2.section + '_' + operand2.session;
    return (itemName1 >= itemName2);
}