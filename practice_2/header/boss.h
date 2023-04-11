#pragma once
#include "workers.h"

class boss :public workers
{
public:
    // constrcutor
    boss(int id, string name, int dID);

    // show infor
    virtual void showInfor();

    // show department name
    virtual string showDepName();
};