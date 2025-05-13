#pragma once
#include "Point3D.h"
#include "TypeSpace3D.h"
#include "TypeColor.h"

class Line3D {
private:
	Point3D startPoint;
	Point3D endPoint;

	int redColor = 0;
	int greenColor = 0;
	int blueColor = 0;

public :
	Line3D() {}
	Line3D(int axis);
	Line3D(Point3D startPoint, Point3D endPoint) : startPoint(startPoint), endPoint(endPoint) {}

	Line3D(double x1, double y1, double x2, double y2) {
		update(x1, y1, x2, y2);
	}

	void update(double x1, double y1, double x2, double y2) {
		startPoint.x = x1;
		startPoint.y = y1;
		endPoint.x = x2;
		endPoint.y = y2;
	}

	void updateColor(int r, int g, int b) {
		redColor = r;
		greenColor = g;
		blueColor = b;
	}
	
	void updateColor(int type);

	void draw() {
		glBegin(GL_LINES);
		glColor3ub(redColor, greenColor, blueColor);
		glVertex3f(startPoint.x, startPoint.y, startPoint.z);
		glVertex3f(endPoint.x, endPoint.y, endPoint.z);
		glEnd();
	}
};