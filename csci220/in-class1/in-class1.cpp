#include <iostream>

using namespace std;

class A
{
    public:
        A()
        {
            cout << "A:Construct\n";
        }
        void print1()
        {
            cout << "A:print1()\n";
        }
        virtual void print2()
        {
            cout << "A:print2()\n";
        }
        virtual void print3()
        {
            cout << "A:print3()\n";
        }

};

class B : public A
{
    public:
        B()
        {
            cout << "B:Construct\n";
        }

        void print2()
        {
            cout << "B:print2()\n";
        }
        void print3()
        {
            cout << "B:print3()\n";
        }
};

class C : public A
{
    public:
        C()
        {
            cout << "C:Construct\n";
        }
        void print1()
        {
            cout << "C:print1()\n";
        }
        void print2()
        {
            cout << "C:print2()\n";
        }
        void print3()
        {
            cout << "C:print3()\n";
        }
};


int main()
{
    A *pA;
    pA = new A();	// syntax error

    pA = new B();	// create an object of type B
    pA->print1();	// run A’s print1()
    pA->print2();	// run B’s print2()
    pA->print3();	// run B’s print3()

    pA = new C();	// create an object of type C
    pA->print1();	// run A’s print1()
    pA->print2();	// run C’s print2()
    pA->print3();	// run C’s print3()

    B *pB;
    pB = new B();	// create an object of type B
    pB->print1();	// run A’s print1()
    pB->print2();	// run B’s print2()
    pB->print3();	// run B’s print3()

    C *pC;
    pC = new C();	// create an object of type C
    pC->print1();	// run C’s print1()
    pC->print2();	// run C’s print2()
    pC->print3();	// run C’s print3()

    return 0;
}