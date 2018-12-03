#include <iostream>
#include <fstream>
#include <ctime>
#include <ratio>
#include <chrono>
#include "Tree.h"

using namespace std;

int main()
{
   /* Tree t;
    cout << "Tree with nothing" << endl;
    t.walk();
    t.addValue(8);
    cout << "Add eight" << endl;
    t.walk();
    t.addValue(6);
    cout << "Add six" << endl;
    t.walk();
    t.addValue(4);
    cout << "Add four" << endl;
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
    t.deleteValue(22);
    cout << "Delete twenty-two" << endl;
    t.walk();
    t.deleteValue(2);
    cout << "Delete two" << endl;
    t.walk();
    t.deleteValue(6);
    cout << "Delete six" << endl;
    t.walk();
      t.deleteValue(5);
    cout << "Delete five" << endl;
    t.walk();
       t.deleteValue(2);
    cout << "Delete two" << endl;
    t.walk();
*/

    using namespace std::chrono;
    //high_resolution_clock::time_point t1 = high_resolution_clock::now();

    Tree r;
    ifstream inFile;
    inFile.open("RandomNums.txt");

   if(!inFile) {
        cerr << "Unable to open file";
        exit(1);
    }

    int x = 0;
    while(inFile>> x) {
        r.addValue(x);
    }

    inFile.close();
   // high_resolution_clock::time_point t2 = high_resolution_clock::now();
    //duration<double> time_span = duration_cast<duration<double>>(t2-t1);
    //std:: cout << "It took " << time_span.count() << " seconds." << std::endl;
/*
   high_resolution_clock::time_point t3 = high_resolution_clock::now();
   ifstream fin;
   fin.open("delete.txt");

    if(!fin) {
        cerr << "Unable to open file";
        exit(1);
    }
    int counter = 0;
    while(fin >> x) {
        r.deleteValue(x);
        cout << counter << endl;
        counter++;
    }

    fin.close();
    high_resolution_clock::time_point t4 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t4-t3);
    std:: cout << "It took " << time_span.count() << " seconds." << std::endl;
*/
    high_resolution_clock::time_point t5 = high_resolution_clock::now();
    ifstream fin;
    fin.open("search.txt");

    if(!fin) {
        cerr << "Unable to open file";
        exit(1);
    }
    int counter = 0;
    while(fin >> x) {
        r.findTest(x);
        cout << counter << endl;
        counter++;
    }

    fin.close();
    high_resolution_clock::time_point t6 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t6-t5);
    std:: cout << "It took " << time_span.count() << " seconds." << std::endl;

    return 0;
}
