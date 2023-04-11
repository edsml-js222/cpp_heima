#include "../header/manager.h"

manager::manager(int id, string name, int dID)
{
    this->m_dID = id;
    this->m_name = name;
    this->m_dID = dID;
}

void manager::showInfor()
{
    cout << "Employee ID: " << m_id
        << "\tEmployee Name: " << m_name
        << "\tEmployee Deparment Name: " << this->showDepName()
        << "\nDepartment Responsibility: Finish the job assigned by the boss and assign job to the employees" << endl;
}

string manager::showDepName()
{
    return string("Manager");
}