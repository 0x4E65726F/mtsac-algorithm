#ifndef DECORATOR_H
#define DECORATOR_H

#include <map>
#include <string>
#include "Object.h"

using namespace std;

class Decorator 
{
private:						                // member data
    std::map<string, Object*> map;			    // the map
public:
    Object* get(const string& a)			    // get value of attribute
    { 
        return map[a];
    }
    void set(const string& a, Object* d)		// set value
    { 
        map[a] = d; 
    }
};

#endif