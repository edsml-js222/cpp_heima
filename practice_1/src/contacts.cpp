#include <iostream>
#include <string>
#define MAX 1000

using namespace std;

// design the contact struct
struct Person
{
    // name
    string m_Name;
    // gender
    int m_Gender;
    // age
    int m_Age;
    // phone number
    string m_Phone;
    // home address
    string m_Addr;
};

// design the address book struct

struct Addressbook
{
    // array used to store the contacts
    struct Person PersonArray[MAX];

    // record the size of the addressbook
    int m_Size;
};

//create a menu 
void showMenu()
{
    // add contacts
    cout << "*************************************" << endl;
    cout << "***** 1. add contacts           *****" << endl;
    // show contacts
    cout << "***** 2. show contacts          *****" << endl;
    // delete contacts
    cout << "***** 3. delete contacts        *****" << endl;
    // find contacts
    cout << "***** 4. find contacts          *****" << endl;
    // modify contacts
    cout << "***** 5. modify contacts        *****" << endl;
    // clear all the contacts
    cout << "***** 6. clear all the contacts *****" << endl;
    // exit the program
    cout << "***** 0. exit the program       *****" << endl;
    cout << "*************************************" << endl;

}

// the function for adding contacts to the addressbook
void addPerson(Addressbook &ads)
{
    // check if the addressbook is full or not
    if (ads.m_Size >= MAX)
    {
        cout << "The addressbook capacity has reached the upper limit, please delete some contacts." << endl;
        return;
    }
    else
    {
        // input the name
        string name;
        cout << "Please input the name: " << endl;
        cin >> name;
        ads.PersonArray[ads.m_Size].m_Name = name;

        // input the gender
        int gender;
        cout << "Please input the gender: " << endl;
        cout << "1 --- male \n2 --- female" << endl;
        while (true)
        {
            cin >> gender;
            if (gender == 1 || gender == 2)
            {
                ads.PersonArray[ads.m_Size].m_Gender = gender;
                break;
            }
            else
            {
                cout << "Unvalid gender, please input again: " << endl;
            }
        }

        // input the age
        int age;
        cout << "Please input the age: " << endl;
        while (true)
        {   
            cin >> age;
            if (age > 0 && age < 120)
            {
                ads.PersonArray[ads.m_Size].m_Age = age;
                break;
            }
            else 
            {
                cout << "Unvalid age, please input again: " << endl;
            }
        }

        // input the phone number
        string phone;
        cout << "Please input the phone number: " << endl;
        cin >> phone;
        cin.ignore(); // skip to the next new line to avoid any pause failure
        ads.PersonArray[ads.m_Size].m_Phone = phone;

        // input the home address
        string addr;
        cout << "Please input the home address: " << endl;
        getline(cin, addr); // the address might have space in the input so using getline
        ads.PersonArray[ads.m_Size].m_Addr = addr;

        // increase the size of the addressbook
        ads.m_Size++;

        cout << "Add contact sucessfully!" << endl;
        
        // clear the previous results
        //system("clear");
    }
}

void showPerson(Addressbook & ads)
{
    if (ads.m_Size == 0)
    {
        cout << "The addressbook is empty, please add your contacts." << endl;
    }
    else
    {
        for (int i = 0; i < ads.m_Size; i++)
        {
            cout << "Name: " << ads.PersonArray[i].m_Name << "\t";
            cout << "Gender: " << (ads.PersonArray[i].m_Gender == 1 ? "Male" : "Female") << "\t";
            cout << "Age: " << ads.PersonArray[i].m_Age << "\t";
            cout << "Phone number: " << ads.PersonArray[i].m_Phone << "\t";
            cout << "Home address: " << ads.PersonArray[i].m_Addr << endl;
        }
        cout << "All your contacts have been showed!" << endl;
    }
    //system("clear");
}

// check if the contact is in the addressbook or not
int isExist(Addressbook &ads, string name)
{
    for (int i = 0; i < ads.m_Size; i++)
    {
        if (ads.PersonArray[i].m_Name == name)
        {
            return i;
        }
    }
    return -1;
}

// delete the contact
void deletePerson(Addressbook &ads)
{   
    string name;
    cout << "Please input the name of the contact you want to delete" << endl;
    cin >> name;
    // pos == -1 can't find the contact
    // pos != -1 can find the contact
    int pos(isExist(ads, name));
    if (pos != -1)
    {   
        // find the contact and then delete the contact
        for (int i = pos; i < ads.m_Size; i++)
        {   
            // repalce the data we want to delete with the next contact's information
            ads.PersonArray[i] = ads.PersonArray[i+1];
            // update the number of contacts in the addressbook
            ads.m_Size--;
            cout << "Delete the contact successfully!" << endl;
        }
    }
    else
    {
        cout << "Can't find the contact in the addressbook" << endl;
    }
}

// find the contact
void findPerson(Addressbook &ads)
{
    string name;
    cout << "Please input the name of the contact you want to find" << endl;
    cin >> name;
    // pos == -1 can't find the contact
    // pos != -1 can find the contact
    int pos(isExist(ads, name));
    if (pos != -1)
    {   
        // find the contact and then show the information
        cout << "Name: " << ads.PersonArray[pos].m_Name << "\t";
        cout << "Gender: " << (ads.PersonArray[pos].m_Gender == 1 ? "Male" : "Female") << "\t";
        cout << "Age: " << ads.PersonArray[pos].m_Age << "\t";
        cout << "Phone number: " << ads.PersonArray[pos].m_Phone << "\t";
        cout << "Home address: " << ads.PersonArray[pos].m_Addr << endl;
        cout << "Find successfully!" << endl;
    }
    else
    {
        cout << "Can't find the contact in the addressbook" << endl;
    }
}

// modify the contact
void modifyPerson(Addressbook &ads)
{
    // 
    cout << "Please input the name of the contact you want to modify: " << endl;
    string name;
    cin >> name;
    int pos(isExist(ads, name));
    // pos == -1
    // pos != -1
    if (pos != -1)
    {
        // name
        cout << "The name you want to modify to: " << endl;
        string name;
        cin >> name;
        ads.PersonArray[pos].m_Name = name;
        // gender
        cout << "The gender you want to modify to: " << endl;
        cout << "1 --- male \n2 --- female" << endl;
        int gender;
        while (true)
        {
            cin >> gender;
            if (gender == 1 || gender == 2)
            {
                ads.PersonArray[pos].m_Gender = gender;
                break;
            }
            else
            {
                cout << "Unvalid gender, please input again: " << endl;
            }
        }
        // age
        cout << "The age you want to modify to: " << endl;
        int age;
        while (true)
        {
            cin >> age;
            if (age > 0 && age < 120)
            {
                ads.PersonArray[pos].m_Age = age;
                break;
            }
            else
            {
                cout << "Unvalid age, please input again: " << endl;
            }
        }
        // phone number
        cout << "The phone number you want to modify to: " << endl;
        string phone;
        cin >> phone;
        cin.ignore(); // skip to the next line to avoid pause failure
        ads.PersonArray[pos].m_Phone = phone;
        // home address
        cout << "The home address you want to modify to: " << endl;
        string addr;
        getline(cin, addr); // the home address input might have space in it
        ads.PersonArray[pos].m_Addr = addr;
        // Prompt the modification is successful
        cout << "Modify successfully!" << endl;
    }
    else 
    {
        cout << "Can't find the contact in the addressbook" << endl;
    }
}

// clear all the contacts
void clearPerson(Addressbook &ads)
{
    cout << "Please confirm that you do want to clear all the contacts: " << endl;
    cout << "1 --- clear \n2 --- don't want to clear" << endl;
    int confirm = 0;
    cin >> confirm;
    switch(confirm)
    {
        case 1:
            // set the number of the contacts to be 0
            ads.m_Size = 0;
            cout << "The addressbook has been set to empty" << endl;
        case 2:
            cout << "Cancel clearing all the contacts" << endl;
    }
}

int main()
{   
    // create and initialize an addressbook object 
    Addressbook ads;
    ads.m_Size = 0;
    // realize different functions according to teh users' input
    int select(0);
    while (true)
    {   
        showMenu();
        cin >> select;
        switch (select)
        {
            case 1: // add contacts
                addPerson(ads);
                break;

            case 2: // show contacts
                showPerson(ads);
                break;

            case 3: // delete contacts
                deletePerson(ads);
                break;

            case 4: // find contacts
                findPerson(ads);
                break;

            case 5: // modify contacts
                modifyPerson(ads);
                break;

            case 6: // clear contacts
                clearPerson(ads);
                break;

            case 0: // exit the program
                cout << "Welcome your next use! Bye!" << endl;
                return 0;
                break;
        
        }
    }
    //system("pause") -- this is only avaiable in Windows
    return 0;
}