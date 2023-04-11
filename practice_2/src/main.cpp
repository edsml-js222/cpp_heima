#include "../header/workManager.h"


int main()
{   
    workManager wm; // generate the workmanager object
    int choice = 0; // initialize the function choice

    while (true)
    {
    // show the menu
    wm.showMenu();

    cout << "Please input the function number you want to achieve: " << endl;
    cin >> choice;

    switch (choice)
    {
    case 0: // exit the porgram 
        
        break; // add the employees' information
    case 1:
        
        break;
    case 2: // show the employees' information
        
        break;
    case 3: // delete the employees' information
        
        break;
    case 4: // modify the employees' information
        
        break;
    case 5: // find the employees' information
        
        break;
    case 6: // sort the employees' information
        
        break;
    case 7: // clear the employees' information
        
        break;

    default:
        break;
    }
    }
    
    return 0;
}