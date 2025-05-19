#include "Cube.h"


void Cube::rotateAndUpdatePosition(int x, int y, int z, int type, double angle) {
	if (angle == 90 || angle == -90) {
		updatePosition(x, y, z);

	}
	moving = true;
	rotateCube(type, angle);
}

void Cube::resetMovingFalse() {
	moving = false;
}

void Cube::rotateCube(int type, double angle) {
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

void Cube::rotateFaces(double angle, int type) {
	for (int i = 0; i < 3; i++) {
		if (angle == 90 || angle == -90) {
			face[i].realRotatePolygon_RotateAnimation(angle, type);
		}
		else {
			face[i].rotatePolygon_RotateAnimation(angle, type);
		}
	}
}