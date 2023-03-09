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
    this->automate->setFlux("1+1");
    assert(automate->analyse() == 2);

    this->automate->setFlux("2+3");
    cout << "Alors ?? " << automate->analyse() << endl;
    cout << "size =  " <<  to_string(automate->analyse()).length() << endl;
    assert(automate->analyse() == 5);

    this->automate->setFlux("5+7");
    assert(automate->analyse() == 12);

    this->automate->setFlux("10+20+30+40");
    assert(automate->analyse() == 100);

    this->automate->setFlux("8+2+3+4+5+6+7+8+9+10");
    assert(automate->analyse() == 62);

    this->automate->setFlux("2*3");
    assert(automate->analyse() == 6);

    this->automate->setFlux("5*7");
    assert(automate->analyse() == 35);

    /* this->automate->setFlux("10*20*30*40");
    assert(automate->analyse() == 240000);*/

    this->automate->setFlux("2*2*2*2*2*2*2*2*2*2");
    assert(automate->analyse() == 1024);

    this->automate->setFlux("3*3*3*3*3*3*3*3*3*3");
    assert(automate->analyse() == 59049);

    this->automate->setFlux("2+3*4");
    assert(automate->analyse() == 14);

    this->automate->setFlux("6*5+4");
    assert(automate->analyse() == 34);

    this->automate->setFlux("(2+3)*(6+4)");
    assert(automate->analyse() == 50);

    this->automate->setFlux("8+(5+3)");
    assert(automate->analyse() == 16);

    /* this->automate->setFlux("10+(20+30)*40");
    assert(automate->analyse() == 12010);*/

    this->automate->setFlux("(1+1)");
    assert(automate->analyse() == 2);

    this->automate->setFlux("(2+3)");
    assert(automate->analyse() == 5);

    this->automate->setFlux("(5+7)");
    assert(automate->analyse() == 12);

    this->automate->setFlux("(10+20+30+40)");
    assert(automate->analyse() == 100);

    this->automate->setFlux("(8+2+3+4+5+6+7+8+9+10)");
    assert(automate->analyse() == 62);

    this->automate->setFlux("(2*3)");
    assert(automate->analyse() == 6);

    this->automate->setFlux("(5*7)");
    assert(automate->analyse() == 35);

    this->automate->setFlux("(10*20*30*40)");
    assert(automate->analyse() == 240000);

    /* this->automate->setFlux("(2+2+2)*(3+3+3)");
    assert(automate->analyse() == 36);*/

    /* this->automate->setFlux("(2+2)*(3+3)*(4+4)");
    assert(automate->analyse() == 96);*/
}