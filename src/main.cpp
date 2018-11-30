#include <iostream>
#include "Tree.h"

using namespace std;

int main()
{
    Tree t;
    t.addValue(8);
    t.addValue(6);
    t.addValue(10);
    t.addValue(22);
    t.addValue(13);
    t.addValue(2);
    t.walk();
    return 0;
}
