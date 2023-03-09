#include "test.h"

Test::Test()
{
    this->automate = new Automate("");
}
    
Test::~Test() 
{
    delete this->automate;
}

void Test::runUnitTests()
{
    cout << "---------------------------------Beginning of tests---------------------------------" << endl << endl;

    this->automate->setFlux("1+1");
    assert(automate->analyse() == 2);
   
    this->automate->reset("2+3");
    assert(automate->analyse() == 5);

    this->automate->reset("5+7");
    assert(automate->analyse() == 12);

    this->automate->reset("10+20+30+40");
    assert(automate->analyse() == 100);

    this->automate->reset("8+2+3+4+5+6+7+8+9+10");
    assert(automate->analyse() == 62);

    this->automate->reset("2*3");
    assert(automate->analyse() == 6);

    this->automate->reset("5*7");
    assert(automate->analyse() == 35);

    this->automate->reset("10*20*30*40");
    assert(automate->analyse() == 240000);

    this->automate->reset("2*2*2*2*2*2*2*2*2*2");
    assert(automate->analyse() == 1024);

    this->automate->reset("3*3*3*3*3*3*3*3*3*3");
    assert(automate->analyse() == 59049);

    this->automate->reset("2+3*4");
    assert(automate->analyse() == 14);

    this->automate->reset("6*5+4");
    assert(automate->analyse() == 34);

    this->automate->reset("(2+3)*(6+4)");
    assert(automate->analyse() == 50);

    this->automate->reset("8+(5+3)");
    assert(automate->analyse() == 16);

    this->automate->reset("10+(20+30)*40");
    assert(automate->analyse() == 2010);

    this->automate->reset("(1+1)");
    assert(automate->analyse() == 2);

    this->automate->reset("(2+3)");
    assert(automate->analyse() == 5);

    this->automate->reset("(5+7)");
    assert(automate->analyse() == 12);

    this->automate->reset("(10+20+30+40)");
    assert(automate->analyse() == 100);

    this->automate->reset("(8+2+3+4+5+6+7+8+9+10)");
    assert(automate->analyse() == 62);

    this->automate->reset("(2*3)");
    assert(automate->analyse() == 6);

    this->automate->reset("(5*7)");
    assert(automate->analyse() == 35);

    this->automate->reset("(10*20*30*40)");
    assert(automate->analyse() == 240000);

    this->automate->reset("(2+2+2)*(3+3+3)");
    assert(automate->analyse() == 54);

    this->automate->reset("(2+2)*(3+3)*(4+4)");
    assert(automate->analyse() == 192);

    this->automate->reset("2+()");
    assert(automate->analyse() == -1);

    this->automate->reset("2+a");
    assert(automate->analyse() == -1);

    cout << "---------------------------------End of tests---------------------------------" << endl << endl;
}