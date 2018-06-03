#include "IStar.h"
#define LIBAPP_HPP
#include <iostream>
//#include <iomanip>
#include <queue>
#include <string>
#include <math.h>
#include <time.h>
#include <stdio.h>  
using namespace std;



int main()
{
	srand(time(NULL));

	// create empty map
	for (int y = 0; y<m; y++)
	{
		for (int x = 0; x<n; x++) map[x][y] = 0;
	}


	//select start and finish locations
	int xA, yA, xB, yB;
	cout << "Enter x start: ";
	cin >> xA;
	cout << "Enter y start: ";
	cin >> yA;
	cout << "Enter x finish: ";
	cin >> xB;
	cout << "Enter y finish: ";
	cin >> yB;
	cout << endl;
	
	start(xA, yA, xB, yB, false);
	getchar(); // wait for a (Enter) keypress  
	return(0);
}