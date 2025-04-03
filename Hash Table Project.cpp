// Hash Table Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "schedule.h"

using namespace std;
const string FILENAME = "Filtered_Summer2022.csv";
void showMenu();
int strHashFunction(string key);

int main()
{
    schedule semester(179);
    int choice;
    string target1, target2;

    ifstream inFile;
    inFile.open(FILENAME);
    if (!inFile)
    {
        cout << "Could not open schedule file." << endl;
        return -1;
    }

    //semester.setHashFunction(strHashFunction);
    semester.initSchedule(inFile);

    do
    {
        showMenu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the 3 character subject code to find: ";
            cin >> target1;
            semester.findSub(target1);
            break;
        case 2:
            cout << "Enter the 3 character subject code and catalog number to find: ";
            cin >> target1 >> target2;
            semester.findSubCat(target1, target2);
            break;
        case 3:
            cout << "Enter the last name of the instructor to find: ";
            cin >> target1;
            semester.findInstructor(target1);
            break;
        case 4:
            semester.print();
            break;
        case 5:
            //semester.statistics();
            cout << "Not yet implemented" << endl;
            break;
        case 6:
            break;
        default:
            cout << "Invalid choice, try again." << endl;
        }
    } while (choice != 6);

    return 0;
}

void showMenu()
{
    cout << endl;
    cout << "Select one of the following actions: " << endl;
    cout << "1 - Search by subject" << endl;
    cout << "2 - Search by subject and category" << endl;
    cout << "3 - Search by instructor" << endl;
    cout << "4 - Print all entries." << endl;
    cout << "5 - Show statistics." << endl;
    cout << "6 - Quit." << endl;
    cout << endl;
}

int strHashFunction(string key)
{

    size_t hashVal = 0;


    // Figure 5.2 hash function
    //for (auto ch : key)
      //hashVal += ch;
    //Figure 5.3 hash function */
       // hashVal = key[0] + 27 * key[1] + 729 * key[2];
        //hashVal = key[0] + 27 * key[4] + 729 * key[8];
        //hashVal = key[0] + key[1] + key[2] + 27 * (key[4] + key[5] + key[6]) + 729 * (key[8] + key[9] + key[10]);

        // Fig 5.4 hash function
        //for (char ch : key)
          //hashVal = 37 * hashVal + ch;

    //Default hash function
    hashVal = (hash<string>()(key));

    //A made up hash function
  //hashVal = key[0] + key[1] + key[2];

    return hashVal;
}


