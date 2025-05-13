#include "Line3D.h"

Line3D::Line3D(int axis) {
	switch (axis) {
	case TypeSpace3D::AXIS_OX:
		startPoint.x = -1000;
		startPoint.y = 0;
		startPoint.z = 0;
		endPoint.x = 1000;
		endPoint.y = 0;
		endPoint.z = 0;
		updateColor(TypeColor::COLOR_RED);
		break;
	case TypeSpace3D::AXIS_OY:
		startPoint.x = 0;
		startPoint.y = -1000;
		startPoint.z = 0;
		endPoint.x = 0;
		endPoint.y = 1000;
		endPoint.z = 0;
		updateColor(TypeColor::COLOR_GREEN);
		break;
	case TypeSpace3D::AXIS_OZ:
		startPoint.x = 0;
		startPoint.y = 0;
		startPoint.z = -1000;
		endPoint.x = 0;
		endPoint.y = 0;
		endPoint.z = 1000;
		updateColor(TypeColor::COLOR_BLUE);
		break;
	}
}


void Line3D::updateColor(int type) {
	switch (type) {
	case TypeColor::COLOR_RED:
		redColor = 255;
		greenColor = 0;
		blueColor = 0;
		break;
	case TypeColor::COLOR_GREEN:
		redColor = 0;
		greenColor = 255;
		blueColor = 0;
		break;
	case TypeColor::COLOR_BLUE:
		redColor = 0;
		greenColor = 0;
		blueColor = 255;
		break;
	case TypeColor::COLOR_YELLOW:
		redColor = 255;
		greenColor = 255;
		blueColor = 0;
		break;
	case TypeColor::COLOR_WHITE:
		redColor = 255;
		greenColor = 255;
		blueColor = 255;
		break;
	case TypeColor::COLOR_ORANGE:
		redColor = 247;
		greenColor = 91;
		blueColor = 0;
		break;
	default:
		break;
	}
}
