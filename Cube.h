#pragma once

#include <vector>
#include "Plane3D.h"
#include "Position3D.h"
#include "TypeRotate.h"
class Cube {
private:
	Position3D position;
	bool moving = false;


public:
	Plane3D face[3];

	Cube(){}
	Cube(Position3D position) {
		this->position = position;
	}
	Cube(int x, int y, int z) {
		updatePosition(x, y, z);
	}

	Position3D getPosition() {
		return position;
	}

	bool isMoving() {
		return moving;
	}

	void updatePosition(int x, int y, int z)
	{
		position.x = x;
		position.y = y;
		position.z = z;
	}

	void rotateAndUpdatePosition(int x, int y, int z, int type, double angle);

	void resetMovingFalse();

	void rotateCube(int type, double angle);

	void rotateFaces(double angle, int type);

	void draw() {
		for (int i = 0; i < 3; i++) {
			face[i].draw();
		}	
	}
};
