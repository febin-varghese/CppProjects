/*
Program to practice class
*/

#include <cstdio>
using namespace std;

class c1
{
    private:
        int i = 0;
    public:
        c1();  // default constructor
        void setvalue(const int &);
        int getvalue();
        ~c1();  // default destructor
};

c1::c1()
{
    puts("Default constructor");
}

void c1::setvalue(const int & value)
{
    i = value;
}

int c1::getvalue()
{
    return i;
}

c1::~c1()
{
    puts("Default destructor");
}

int main()
{
    c1 test;
    test.setvalue(1);
    printf("Value = %d\n", test.getvalue());
    return 0;
}
