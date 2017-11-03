#include<ctime>
#include<iostream>


#include "manipulator.h"

// каждый линк должен знать угловые отклонения от осей своей точки А 
// и общий твист угол



int main() {

	clock_t tStart = clock();

	const byte numLinks = 2;
	Range r(PIdiv2, -PIdiv2);
	Link links[numLinks];
	
	links[0] = Link(10, new RevolutionJoint(r, PIdiv4), Angles(PIdiv2, 0.0, 0.0));
	links[1] = Link(10, new RotationJoint(r, PIdiv4));
	//links[2] = Link(10, new RotationJoint(r, 0.0));

	Manipulator manip(links, numLinks);

	Point pos = manip.computePosition();
	printf("\nPosition: x=%.2f, y=%.2f, z=%.2f", pos.x, pos.y, pos.z);



	printf("Time taken: %.8fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

	system("pause");
	return 0;
}