#pragma once
#include <iostream>
#include "automate.h"
#include <cassert>
using namespace std;

class Test {
    public :
        Test();
        ~Test();
        void runUnitTests();
    
    protected :
        Automate * automate;
};