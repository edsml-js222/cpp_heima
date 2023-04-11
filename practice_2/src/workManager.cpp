#include "../header//workManager.h"

workManager::workManager()
{

}

void workManager::showMenu()
{
    // add employees' infomation
    cout << "**************************************************" << endl;
    cout << "***** 1. Add employees                       *****" << endl;
    // show employees' infomation
    cout << "***** 2. Show employees                      *****" << endl;
    // delete employees' information
    cout << "***** 3. Delete employees                    *****" << endl;
    // modify employees' infomation
    cout << "***** 4. Modify employees                    *****" << endl;
    // find employees
    cout << "***** 5. Find employees                      *****" << endl;
    // sort the employees' ID
    cout << "***** 6. Sort employees' ID                  *****" << endl;
    // clear all the employees
    cout << "***** 7. Clear all the employees' infomation *****" << endl;
    // exit the program
    cout << "***** 0. Exit the program                    *****" << endl;
    cout << "**************************************************" << endl;
}

void workManager::exitSystem()
{
    cout << "Welcome to your next usage! Bye!" << endl;
    exit(0);
}

workManager::~workManager()
{

}
