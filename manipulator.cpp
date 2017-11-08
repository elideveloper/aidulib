#include "manipulator.h"

#include "ga_params.h"
#include "utility.h"

Manipulator::Manipulator(Link* links, int numLinks, Angles startingPos) : _links(links), _numLinks(numLinks), _startingPosition(startingPos)
{
}

Point Manipulator::computePosition()
{
	this->_links[0].setAngles(this->_startingPosition);			// set starting position for first link
	Point p = this->_links[0].computeB();
	for (register byte i = 1; i < this->_numLinks; i++) {
		this->_links[i].setA(p);
		this->_links[i].setAngles(this->_links[i - 1].getAngles());
		p = this->_links[i].computeB(this->_links[i - 1]);
	}
	return p;
}

void Manipulator::reachPosition(Point dest)
{
	Link** gen = this->createGeneration();
	this->sortGeneration(gen, dest);
	for (register int n = 0; n < maxIterations; n++) {
		for (register byte i = numLeaveBest; i < numLeaveBest + numCrossover; i += 2) {
			this->cross(gen[i], gen[i + 1]);
		}
		for (register byte i = numLeaveBest; i < numLeaveBest + numCrossover; i++) {
			this->tryMutate(gen[i], mutateProb);
		}
		for (register byte i = numLeaveBest + numCrossover; i < numIndividuals; i++) {
			for (register byte j = 0; j < this->_numLinks; j++) {
				gen[i][j].randomizeAngle();
			}
		}
		this->sortGeneration(gen, dest);
	}

	for (register byte j = 0; j < this->_numLinks; j++) {
		this->_links[j] = gen[0][j];
	}

	// release memory
	for (register byte i = 0; i < numIndividuals; i++) {
		delete[] gen[i];
	}
	delete[] gen;
}

int * Manipulator::getJointAngles() const
{
	int* angles = new int[this->_numLinks];
	for (register byte i = 0; i < this->_numLinks; i++) angles[i] = this->_links[i].getTurn();
	return angles;
}

Link** Manipulator::createGeneration()
{
	Link** generation = new Link*[numIndividuals];
	for (register byte i = 0; i < numIndividuals; i++) {
		generation[i] = new Link[this->_numLinks];
		for (register byte j = 0; j < this->_numLinks; j++) {
			generation[i][j] = Link(this->_links[j]);
			if (i != 0) generation[i][j].randomizeAngle();
		}
	}
	return generation;
}

void Manipulator::sortGeneration(Link** generation, Point dest)
{
	Link* currLinks = this->_links;
	int errPrev = 0;
	int errCurr = 0;
	Link* tmpLink = nullptr;

	this->_links = generation[numIndividuals - 1];
	errPrev = this->computeError(dest);

	// part of bubble sort, best one from the prev comparison goes to the top
	for (register int i = numIndividuals - 2; i >= 0; i--) {
		this->_links = generation[i];
		errCurr = this->computeError(dest);
		if (errCurr > errPrev) {
			tmpLink = generation[i];
			generation[i] = generation[i + 1];
			generation[i + 1] = tmpLink;
		}
		else {
			errPrev = errCurr;
		}
	}
	this->_links = currLinks;

	/*
	int maxError = 0;
	for (register byte i = 0; i < this->_numLinks; i++) {
		maxError += this->_links[i].getLength();
	}
	maxError *= 2;
	Link* currLinks = this->_links;
	Link** errorsArr = new Link*[maxError]();
	Point pos;
	int error = 0;
	for (register byte i = 0; i < numIndividuals; i++) {
		this->_links = generation[i];
		error = computeError(dest);
		while (errorsArr[error] != nullptr) error++;
		errorsArr[error] = generation[i];
	}

	int j = 0;
	for (register int i = 0; i < maxError; i++) {
		if (errorsArr[i] != nullptr) {
			generation[j] = errorsArr[i];
			if (j == numIndividuals - 1) break;
			j++;
		}
	}
	this->_links = currLinks;
	delete[] errorsArr;
	*/
}

void Manipulator::cross(Link* dad, Link* mom)
{
	for (register byte j = 1; j < this->_numLinks; j += 2) {
		dad[j].swapJoints(mom[j]);
	}
}

void Manipulator::tryMutate(Link* individual, int prob)
{
	byte mutNo = random(this->_numLinks * 100 / prob);
	if (mutNo < this->_numLinks) individual[mutNo].randomizeAngle();
}

// reimplement, introduce obstacles
int Manipulator::computeError(Point dest)
{
	Point pos = this->computePosition();
	for (register byte i = 0; i < this->_numLinks; i++) {
		if (this->_links[i].isIntersectsHorizPlane(0)) {
			return 32000;
		}
	}
	return pos.distanceTo(dest);
}
