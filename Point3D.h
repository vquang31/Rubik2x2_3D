#pragma once
#include <GL/glut.h>
#include <gl/GL.h>
class Point3D {
public:
	double x = 0;
	double y = 0;
	double z = 0;
	Point3D(double x, double y, double z) : x(x), y(y), z(z) {}
	Point3D() {
		x = 0;
		y = 0;
		z = 0;
	}

};