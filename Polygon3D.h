#pragma once
#include <vector>
#include "Point3D.h"
#include <iostream>

class Polygon3D {
public:

	const static int AXIS_OX = 1;
	const static int AXIS_OY = 2;
	const static int AXIS_OZ = 3;

	const static int PLANE_XY = 4;
	const static int PLANE_XZ = 5;
	const static int PLANE_YZ = 6;

	const static int COLOR_RED = 1;
	const static int COLOR_GREEN = 2;
	const static int COLOR_BLUE = 3;
	const static int COLOR_YELLOW = 4;
	const static int COLOR_WHITE = 5;
	const static int COLOR_ORANGE = 6;



	std::vector<Point3D> listPoints;

	int redColor = 256;
	int greenColor = 256;
	int blueColor = 256;

	Polygon3D() {}

	Polygon3D(std::vector<Point3D> listPoints1) {
		update(listPoints1);
	}

	void update(std::vector<Point3D> listPoints1) {
		listPoints = listPoints1;
	}


	void updateColor(int type) {
		switch (type) {
		case COLOR_RED:
			redColor = 255;
			greenColor = 0;
			blueColor = 0;
			break;
		case COLOR_GREEN:
			redColor = 0;
			greenColor = 255;
			blueColor = 0;
			break;
		case COLOR_BLUE:
			redColor = 0;
			greenColor = 0;
			blueColor = 255;
			break;
		case COLOR_YELLOW:
			redColor = 255;
			greenColor = 255;
			blueColor = 0;
			break;
		case COLOR_WHITE:
			redColor = 255;
			greenColor = 255;
			blueColor = 255;
			break;
		case COLOR_ORANGE:
			redColor = 247;
			greenColor = 91;
			blueColor = 0;
			break;
		default:
			break;
		}
	}

	void updateColor(int r, int g, int b) {
		redColor = r;
		greenColor = g;
		blueColor = b;
	}

	void in() {
		for (Point3D p : listPoints) {
			std::cout << p.x << " " << p.y << " " << p.z << std::endl;
		}
	}

	void draw();

	/// <summary>
	/// 
	/// </summary>
	/// <param name="angel">: degree</param>
	/// <param name="axis">AXIS_OX or AXIS_OY or AXIS_OZ</param>
	void rotatePolygon(double angel, int axis);

	void scalePolygon(double x, double y, double z);

	void transformPolygon(double b, double c, double d, double f, double g, double h);


	/// <summary>
	/// 
	/// </summary>
	/// <param name="type">AXIS_OX or AXIS_OY or AXIS_OZ or PLANE_XY or PLANE_XZ or PLANE_YZ</param>
	void symmetryPolygon(int type);

	void movePolygon(double a, double b, double c);

protected:

	void updatePoints(double** C) {
		for (int i = 0; i < listPoints.size(); i++) {
			listPoints[i].x = C[i][0];
			listPoints[i].y = C[i][1];
			listPoints[i].z = C[i][2];
		}
	}


};