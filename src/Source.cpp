#include <iostream>
#include<queue>
#include "ProcessGenerator.h"

using namespace std;

int main()
{
	//testing code
	ProcessGenerator gen("../Input/input", "../Output/output");

	gen.run();

	cout << "done";

	int wait; cin >> wait;
}