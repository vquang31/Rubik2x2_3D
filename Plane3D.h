#pragma once
#include <vector>
#include "Point3D.h"
#include <iostream>
#include "TypeSpace3D.h"
#include "TypeColor.h"
class Plane3D {

private:
	int redColor = 256;
	int greenColor = 256;
	int blueColor = 256;

public:
	std::vector<Point3D> listPoints;
	std::vector<Point3D> listPoints_save;

	Plane3D() {}

	Plane3D(std::vector<Point3D> listPoints1) {
		update(listPoints1);
	}

	void update(std::vector<Point3D> listPoints1) {
		listPoints = listPoints1;
		cloneListPoints_save();
	}

	void cloneListPoints_save();

	void updateColor(int type);

	void updateColor(int r, int g, int b);

	void in() {
		for (Point3D p : listPoints) {
			std::cout << p.x << " " << p.y << " " << p.z << std::endl;
		}
	}

	void draw();

	void realRotatePolygon_RotateAnimation(double degree, int axis);

	void rotatePolygon_RotateAnimation(double angle, int axis);


	/// <summary>
	/// 
	/// </summary>
	/// <param name="angel">: degree</param>
	/// <param name="axis">AXIS_OX or AXIS_OY or AXIS_OZ</param>
	void rotatePolygon(double angle , int axis);

	void scalePolygon(double x, double y, double z);

	void transformPolygon(double b, double c, double d, double f, double g, double h);


	/// <summary>
	/// 
	/// </summary>
	/// <param name="type">AXIS_OX or AXIS_OY or AXIS_OZ or PLANE_XY or PLANE_XZ or PLANE_YZ</param>
	void symmetryPolygon(int type);

	void movePolygon(double a, double b, double c);

	///


protected:

	void updatePoints(double** C) {
		for (int i = 0; i < listPoints.size(); i++) {
			listPoints[i].x = C[i][0];
			listPoints[i].y = C[i][1];
			listPoints[i].z = C[i][2];
		}
	}


};