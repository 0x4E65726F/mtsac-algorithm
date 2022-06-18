// Set up for CSCI 220 Fall 21 by T. Vo
// Code from book 
#pragma once

#include <string>

using namespace std;

class RuntimeException { // generic run-time exception
private:
	string errorMsg;
public:
	RuntimeException(const string& err) { errorMsg = err; }
	string getMessage() const { return errorMsg; }
};