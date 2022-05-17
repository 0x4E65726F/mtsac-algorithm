#pragma once
#include <string>
#include <map>

using namespace std;

// Created by T. Vo for CSCI 230
// Based on C++ code fragment of Goodrich book 

class Object {					// generic object
public:
	virtual double   doubleValue() const;	// throw(bad_cast);
	virtual string   stringValue() const ;	// throw(bad_cast);
};


class String : public Object {
private:
	string value;
public:
	String(string v = "") : value(v) { }
	string getValue() const
	{
		return value;
	}
};


class Double : public Object {
private:
	double value;
public:
	Double(double v = 0) : value(v) { }
	double getValue() const
	{
		return value;
	}
};

double Object::doubleValue() const // throw(bad_cast) {		// cast to Integer
{
	const Double* p = dynamic_cast<const Double*>(this);
	if (p == NULL) throw exception(); // ("Illegal attempt to cast to Integer");
	return p->getValue();
}

string Object::stringValue() const { // throw(bad_cast) {		// cast to String
	const String* p = dynamic_cast<const String*>(this);
	if (p == NULL) throw exception(); // ("Illegal attempt to cast to Srring");
	return p->getValue();
}


class Decorator {
private:									// member data
	std::map<string, Object*> map1;			// the map
public:
	Object * get(const string& a)			// get value of attribute
	{
		return map1[a];
	}
	void set(const string& a, Object* d)	// set value
	{
		map1[a] = d;
	}
};

