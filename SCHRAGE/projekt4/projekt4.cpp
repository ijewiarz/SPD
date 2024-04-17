#include <iostream>
#include <cstdio>
#include "Schrage.h"
#include "Task.h"

using namespace std;


int main()
{
    Data D;
    Schrage A;
    string path = "data1.txt";

    D.readData(path);
    cout << A.SchrpmtnHeap(D);
    //D.showOrderAndCmax();


    cout << "\n\n Press anything to close the program.\n";
    getchar(); // for user-friendly behaviour
    return 0;
}

