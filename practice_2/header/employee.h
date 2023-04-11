#pragma once
#include "workers.h"

class employee :public workers
{
public:
    // constrcutor
    employee(int id, string name, int dID);

    // show infor
    virtual void showInfor();

    // show department name
    virtual string showDepName();
};