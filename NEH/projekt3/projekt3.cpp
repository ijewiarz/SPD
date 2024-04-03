#include <iostream>
#include <fstream>
#include <cstdio>
#include "Task.h"
#include "Neh.h"

using namespace std;


int main() {

    Data D;
    Neh A;
    string path = "test.txt";
    D.readData(path);
    //D.Test();
    //vector<int> tst{ 2, 16, 8, 7, 14, 13, 10, 15, 12, 18, 5, 3, 4, 17, 0, 1, 9, 6, 19, 11};

    //cout << A.countCmax(D, tst) << endl;
    A.findNeh(D);
    D.showOrderAndNeh();



    // end of program
    cout << "\n\n Press anything to close the program.\n";
    getchar(); // for user-friendly behaviour
    return 0;
}