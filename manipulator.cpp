#include "manipulator.h"

Manipulator::Manipulator(Link * links, byte numLinks) : _links(links), _numLinks(numLinks)
{
}

Point Manipulator::computePosition()
{
	Point p = this->_links[0].computeB();
	for (register int i = 1; i < this->_numLinks; i++) {
		this->_links[i].setA(p);
		this->_links[i].setAngles(this->_links[i - 1].getAngles());
		p = this->_links[i].computeB(this->_links[i - 1]);
	}
	return p;
}
