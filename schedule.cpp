#include "schedule.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>


using namespace std;

schedule::schedule(int size): semesterSchedule(size){};

void schedule::addEntry(string key, scheduleItem item)
{
    pair<string, scheduleItem> entry(key, item);
    semesterSchedule.insert(entry);
}

string schedule::getKey(scheduleItem &item) {
    return item.makeKey();
}

void schedule::findSub(string target) {
    unordered_map<string, scheduleItem>::const_iterator it;
    for (auto it = semesterSchedule.begin(); it != semesterSchedule.end(); ++it)
    {
        SchedItem item = it->second.getScheduleItem();
        if (item.subject == target)
        {
            it->second.print();
            cout << endl;
        }
    }
}

void schedule::findSubCat(string target1, string target2) {
    unordered_map<string, scheduleItem>::const_iterator it;
    for (auto it = semesterSchedule.begin(); it != semesterSchedule.end(); ++it)
    {
        SchedItem item = it->second.getScheduleItem();
        if (item.subject == target1 && item.catalog == target2)
        {
            it->second.print();
            cout << endl;
        }  
    }
}

void schedule::findInstructor(string target) {
    unordered_map<string, scheduleItem>::const_iterator it;
    for (auto it = semesterSchedule.begin(); it != semesterSchedule.end(); ++it)
    {
        SchedItem item = it->second.getScheduleItem();
        string lastName;
        int pos = item.instructor.find(",", 0); // Extract the last name
        lastName = item.instructor.substr(0, pos);
        if (lastName == target)
        {
            it->second.print();
            cout << endl;
        }
    }
}

void schedule::print() {
    unordered_map<string, scheduleItem>::const_iterator it;
    for (auto it = semesterSchedule.begin(); it != semesterSchedule.end(); ++it)
    {
        it->second.print();
        cout << endl;
    }
}


void schedule::initSchedule(ifstream &inFile) 
{
    SchedItem item;
    vector<string> headers;
    string line;

    // Read and discard the first line
    getline(inFile, line);
    
    /* 
        Read the rest of the file.  For each row:
        Extract the fields into variables and create a scheduleItem object
        Create the key for the record
        Insert the key and scheduleItem object into the hash table.
    */

    while(getline(inFile, line))
    {
        /*
        Struct field names:
        Tokens(0 - 4) are strings: subject, catalog, section, component, session
        Tokens(5 - 7)  need to be converted to int: units, totEnrl, capEnrl
        Token 8 is a string: instructor
        */
        
        vector<string> fields = getFields(line);
        scheduleItem itemObj(fields[0], fields[1], fields[2], fields[3], fields[4], stoi(fields[5]), stoi(fields[6]), stoi(fields[7]), fields[8]);
        string key = itemObj.makeKey();
        addEntry(key, itemObj);
    }
}

vector<string> schedule::getFields(string line)
{
    std::stringstream ss(line);
    std::vector<std::string> tokens;
    std::string token;
    bool insideQuotes = false;
    char ch;

    while (ss.get(ch)) {
        if (ch == '"') {
            insideQuotes = !insideQuotes; // toggle state
        }
        else if (ch == ',' && !insideQuotes) {
            tokens.push_back(token);
            token.clear();
        }
        else {
            token += ch;
        }
    }
    if (!token.empty()) {
        tokens.push_back(token); // push the last token
    }

    return tokens;
}

void schedule::statistics() 
{
    cout << "Not yet implemente" << endl;
} 

size_t schedule::getTableSize() { /*return semesterSchedule.getSize();*/ return 10;  }

/* void schedule::setHashFunction)
    std::function<size_t(const std::string &)> hashFunc) {
  semesterSchedule.setHashFunction(hashFunc);
}*/
