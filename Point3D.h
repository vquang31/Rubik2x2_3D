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

	Point3D operator-(const Point3D& other) const { return { x - other.x, y - other.y, z - other.z }; }
	Point3D cross(const Point3D& v) const {
		return { y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x };
	}
	float dot(const Point3D& v) const { return x * v.x + y * v.y + z * v.z; }
};