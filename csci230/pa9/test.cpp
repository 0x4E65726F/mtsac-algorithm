#include "Decorator.h"

using namespace std;

int main()
{
    Decorator v; // a decorable object
    v.set("name", new String("Bob")); // store name as “Bob”
    v.set("age", new Integer(23)); // store age as 23
    // . . .
    string n = v.get("name")->stringValue(); // n = “Bob”
    int a = v.get("age")->intValue(); // a = 23
    cout << a;
    return 0;
}

