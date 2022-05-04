#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <exception>
#include <string>

using namespace std;

class BadCast: public exception
{
public:
    BadCast(string str)
    {
        cout << str << endl;
    }
};

class Object {					// generic object
public:
    int      intValue()    const throw(BadCast);
    string   stringValue() const throw(BadCast);
};

class Integer : public Object {
private:
    int value;
public:
    Integer(int v = 0) : value(v) { }
    int getValue() const
    { return value; }
};

class String : public Object {
private:
    string value;
public:
    String(string v = "") : value(v) { }
    string getValue() const
    { return value; }
};

int Object::intValue() const throw(BadCast) {		// cast to Integer
    const Integer* p = dynamic_cast<const Integer*>(this);
    if (p == NULL) throw BadCast("Illegal attempt to cast to Integer");
        return p->getValue();
}


#endif