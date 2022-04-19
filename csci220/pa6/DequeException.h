// Set up for CSCI 220 Fall 21 by T. Vo
// Code from book 
#pragma once
#include "RuntimeException.h"

using namespace std;

class DequeEmpty : public RuntimeException {
public:
    DequeEmpty(const string& err) : RuntimeException(err) { }
};