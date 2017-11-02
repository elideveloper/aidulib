#include<ctime>
#include<iostream>


#include "manipulator.h"

int main() {

	clock_t tStart = clock();

	const byte numLinks = 3;
	Range r(PIdiv2, -PIdiv2);
	Link links[numLinks];
	
	links[0] = Link(10, Joint(r, r, PIdiv4, PIdiv4));
	links[1] = Link(10, Joint(r, r, PIdiv4, PIdiv4));
	links[2] = Link(10, Joint(r, r, PIdiv4, 0));

	Manipulator manip(links, numLinks);

	Point pos = manip.computePosition();
	printf("\nPosition: x=%.2f, y=%.2f, z=%.2f", pos.x, pos.y, pos.z);



	printf("Time taken: %.8fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

	system("pause");
	return 0;
}