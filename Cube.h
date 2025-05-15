#pragma once

#include <vector>
#include "Plane3D.h"
#include "Position3D.h"
#include "TypeRotate.h"
class Cube {


public:

	Position3D position;

	Plane3D face[3];

	bool moving = false;

	Cube(){}
	Cube(Position3D position) {
		this->position = position;
	}

	Cube(int x, int y, int z) {
		updatePosition(x, y, z);
	}

	
	void updatePosition(int x, int y, int z)
	{
		position.x = x;
		position.y = y;
		position.z = z;
	}

	void rotateAndUpdatePosition(int x, int y, int z , int type, double angle) {
		if (angle == 90 || angle == -90) {
			updatePosition(x, y, z);

		}
		moving = true;
		rotateCube(type , angle);
	}

	void resetMovingFalse() {
		moving = false;
	}

	void rotateCube(int type, double angle) {
		switch (type) {
		case TypeRotate::TYPE_L:
		case TypeRotate::TYPE_R_:
			rotateFaces(angle, TypeSpace3D::AXIS_OZ);
			break;
		case TypeRotate::TYPE_L_:
		case TypeRotate::TYPE_R:
			rotateFaces(-angle, TypeSpace3D::AXIS_OZ);
			break;
		case TypeRotate::TYPE_F:
		case TypeRotate::TYPE_B_:
			rotateFaces(angle, TypeSpace3D::AXIS_OX);
			break;
		case TypeRotate::TYPE_F_:
		case TypeRotate::TYPE_B:
			rotateFaces(-angle, TypeSpace3D::AXIS_OX);
			break;
		case TypeRotate::TYPE_D:
		case TypeRotate::TYPE_U_:
			rotateFaces(angle, TypeSpace3D::AXIS_OY);
			break;
		case TypeRotate::TYPE_D_:
		case TypeRotate::TYPE_U:
			rotateFaces(-angle, TypeSpace3D::AXIS_OY);
			break;
		}
	}

	void rotateFaces(double angle, int type) {
		for (int i = 0; i < 3; i++) {
			if (angle == 90 || angle == -90) {
				face[i].realRotatePolygon_RotateAnimation(angle,type);
			}
			else {
				face[i].rotatePolygon_RotateAnimation(angle, type);
			}
		}
	}

	void draw() {
		for (int i = 0; i < 3; i++) {
			face[i].draw();
		}	
	}
};
