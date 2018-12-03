#include <iostream>
#include "Tree.h"

using namespace std;

int main()
{
    Tree t;
    cout << "Tree with nothing" << endl;
    t.walk();
    t.addValue(8);
    cout << "Add eight" << endl;
    t.walk();
    t.addValue(6);
    cout << "Add six" << endl;
    t.walk();
    t.addValue(10);
    cout << "Add ten" << endl;
    t.walk();
    t.addValue(22);
    cout << "Add twenty-two" << endl;
    t.walk();
    t.addValue(13);
    cout << "Add thirteen" << endl;
    t.walk();
    t.addValue(2);
    cout << "Add two" << endl;
    t.walk();
    t.deleteValue(10);
    cout << "Delete ten" << endl;
    t.walk();
    t.deleteValue(2);
    cout << "Delete two" << endl;
    t.walk();
    t.deleteValue(6);
    cout << "Delete six" << endl;
    t.walk();
    return 0;
}
