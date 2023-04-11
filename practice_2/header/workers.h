#pragma once
#include <iostream>
#include <string>
using namespace std;

class workers
{
public:

    virtual void showInfor() = 0; // pure virtual function for showing infor
    virtual string showDepName() = 0; // pure virtual function for showing the department infor

protected:
    int m_id;
    string m_name;
    int m_dID;
};