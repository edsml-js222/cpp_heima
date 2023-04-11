#include "../header/boss.h"

boss::boss(int id, string name, int dID)
{
    this->m_dID = id;
    this->m_name = name;
    this->m_dID = dID;
}

void boss::showInfor()
{
    cout << "Employee ID: " << m_id
        << "\tEmployee Name: " << m_name
        << "\tEmployee Deparment Name: " << this->showDepName()
        << "\nDepartment Responsibility: Assign jobs to the manager" << endl;
}

string boss::showDepName()
{
    return string("Boss");
}