#include <iostream>
#include <cstdio>
#include "Task.h"
#include "Carlier.h"


using namespace std;


int main()
{
    Carlier A;
    Data D;
    string path = "t5s1.txt";
    D.readData(path);

    A.Algorythm(D, INT_MAX);

    D.showOrderAndCmax();










    cout << "\n\n Press anything to close the program.\n";
    //getchar(); // for user-friendly behaviour
    return 0;
}
