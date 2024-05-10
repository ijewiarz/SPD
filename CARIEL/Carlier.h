#pragma once

#include "Task.h"
#include "Schrage.h"

class Carlier
{

public:
	

	void Algorythm(Data& D, int UB);

	int FindB(Data& D, const std::vector<Task>& pi, int U);
	int FindA(Data& D, const std::vector<Task>& pi, int U, int b);
	int FindC(Data& D, const std::vector<Task>& pi, int b, int a);



};

