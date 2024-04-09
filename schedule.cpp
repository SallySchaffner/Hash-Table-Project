#include "schedule.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

schedule::schedule(int size): semesterSchedule(size){};

void schedule::addEntry(scheduleItem &item) {
  string key = getKey(item);
  semesterSchedule.insert(key, item);
}

string schedule::getKey(scheduleItem &item) {
  return item.getSubject() + '_' + item.getCatalog() + '_' + item.getSection();
}

void schedule::findSub(string target) {
  int maxItems = semesterSchedule.maxBucketSize();
  for (size_t i = 0; i < semesterSchedule.getSize(); i++) {
    vector<scheduleItem> items(maxItems);
    items = semesterSchedule.getByIndex(i);
    if (items.size() > 0) {
      for (int j = 0; j < items.size(); j++) {
        if (items[j].getSubject() == target)
          items[j].print();
      }
    }
  }
}

void schedule::findSubCat(string target1, string target2) {
  int maxItems = semesterSchedule.maxBucketSize();
  for (size_t i = 0; i < semesterSchedule.getSize(); i++) {
    vector<scheduleItem> items(maxItems);
    items = semesterSchedule.getByIndex(i);
    if (items.size() > 0) {
      for (int j = 0; j < items.size(); j++) {
          if (items[j].getSubject() == target1 && items[j].getCatalog() == target2)
            items[j].print();
      }
    }
  }
}

void schedule::findInstructor(string target) {
  int maxItems = semesterSchedule.maxBucketSize();
  for (size_t i = 0; i < semesterSchedule.getSize(); i++) {
    vector<scheduleItem> items(maxItems);
    items = semesterSchedule.getByIndex(i);
    if (items.size() > 0) {
      for (int j = 0; j < items.size(); j++) {
        string ins, last;
        ins = items[j].getInstructor();
        int pos = ins.find(",", 0); // Extract the last name
        last = ins.substr(0, pos);
        if (last == target)
          items[j].print();
      }
    }
  }
}

void schedule::print() {
  bool first = true;
  int maxItems = semesterSchedule.maxBucketSize();
  for (size_t i = 0; i < semesterSchedule.getSize(); i++) {
    vector<scheduleItem> items(maxItems);
    items = semesterSchedule.getByIndex(i);
    if (items.size() > 0) {
      for (int j = 0; j < items.size(); j++) {
        if (first) {
          items[j].printHeader();
          first = false;
        }
        items[j].print();
      }
      cout << endl;
    }
  }
}

void schedule::initSchedule(ifstream &inFile) {
  string sub, cat, sec, com, ses, ins;
  int uni, totE, capE;
  char ch;

  // Unused fields
  int minU;
  string org;

  inFile >> sub;

  inFile.ignore(256, '\n'); // ignore header line
  getline(inFile, sub, ',');
  while (!inFile.eof()) {
    getline(inFile, cat, ',');
    getline(inFile, sec, ',');
    getline(inFile, com, ',');
    getline(inFile, ses, ',');
    inFile >> minU >> ch >> uni >> ch >> totE >> ch >> capE >> ch;
    getline(inFile, org, ',');
    inFile.get(); // discard first double quote
    getline(inFile, ins, '\"');
    inFile.get();             // discard ,
    inFile.ignore(256, '\n'); // ignore the rest of the line

    scheduleItem lineItem(sub, cat, sec, com, ses, ins, uni, totE, capE);
    addEntry(lineItem);

    getline(inFile, sub, ',');
  }
}

void schedule::statistics() {
  cout << "Size of the hash table: " << semesterSchedule.getSize() << endl;
  cout << "Number of buckets in hash table: " << semesterSchedule.getBuckets()
       << endl;
  cout << "Load factor of the hash table: " << semesterSchedule.getLoadFactor()
       << endl;
  cout << "Number of collisions in the hash table: "
       << semesterSchedule.countCollisions() << endl;
  cout << "Longest chain: " << semesterSchedule.maxBucketSize() << endl;
  cout << endl;
}

size_t schedule::getTableSize() { return semesterSchedule.getSize(); }

void schedule::setHashFunction(
    std::function<size_t(const std::string &)> hashFunc) {
  semesterSchedule.setHashFunction(hashFunc);
}
