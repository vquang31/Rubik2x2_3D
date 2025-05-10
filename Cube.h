#pragma once

#include <vector>
#include "Polygon3D.h"
#include "Position3D.h"

class Cube {


public:
	Position3D position;

	Polygon3D face[3];

	Cube(){}
	Cube(Position3D position) {
		this->position = position;
	}

	Cube(int x, int y, int z) {
		update(x, y, z);
	}

	
	void update(int x, int y, int z)
	{
		position.x = x;
		position.y = y;
		position.z = z;
	}


};
