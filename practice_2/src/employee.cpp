#include "../header/employee.h"

employee::employee(int id, string name, int dID)
{
    this->m_dID = id;
    this->m_name = name;
    this->m_dID = dID;
}

void employee::showInfor()
{
    cout << "Employee ID: " << m_id
        << "\tEmployee Name: " << m_name
        << "\tEmployee Deparment Name: " << this->showDepName()
        << "\nDepartment Responsibility: Finish the job assigned by the manager" << endl;
}

string employee::showDepName()
{
    return string("Employee");
}