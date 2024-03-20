#include <iostream>
#include <cstdio>
#include "Alg.h"

using namespace std;



int main()
{
    Alg* A = new Schrage;

    A->readData("data1.txt");
    A->readData("data2.txt");
    A->readData("data3.txt");
    A->readData("data4.txt");

    A->calcCsum();
    A->showAllData();


    cout << "\n\n Ppress anything to close the program.\n";
    getchar(); // for user-friendly behaviour
    return 0;
}


