
#include <iostream>
#include <cstdio>
#include "Alg.h"
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

int main()
{
    Data D;
    Alg A;
    string path = "data10.txt";
    D.readData(path); // for n = 11 -> T = ~345s, for n = 10 -> T = ~29s

    // dynamic programing and time calculations
    auto start = high_resolution_clock::now();
    A.PD(D);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);

    // show resoults
    D.showOrderAndWiti();
    cout << "TIME: " << duration.count() << "s" << endl;

    // save time to a file
    ofstream f("time.txt", ofstream::trunc);
    f << path << ": " << duration.count() << "s";
    f.close();
    
    // end of program
    cout << "\n\n Press anything to close the program.\n";
    getchar(); // for user-friendly behaviour
    return 0;
}

