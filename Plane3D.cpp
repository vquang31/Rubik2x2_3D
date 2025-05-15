#include "CommonMethod.h"
#include "Plane3D.h"

void Plane3D::draw() {
	
	// draw face
	 
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(redColor, greenColor,  blueColor);

	for (Point3D p : listPoints) {
		glVertex3f(p.x, p.y, p.z);
	}
	glEnd();

	glBegin(GL_LINES);
	glColor3ub(0, 0, 0);

	size_t n = listPoints.size();
	for (size_t i = 0; i < n; ++i) {
		const Point3D& p1 = listPoints[i];
		const Point3D& p2 = listPoints[(i + 1) % n]; // lặp lại để nối điểm cuối với đầu
		glVertex3f(p1.x, p1.y, p1.z);
		glVertex3f(p2.x, p2.y, p2.z);
	}



	glEnd();

	// draw line 

}


void Plane3D::updateColor(int type) {
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


void Plane3D::rotatePolygon(double angle, int axis) {
	double PI = 2 * acos(0.0);
	double angleRad = PI / 180 * angle;
	double** A = CommonMethod::createPolygonMatrix_3D(*this);
	double** B = CommonMethod::createUnitMatrix(3);

	switch (axis) {
	case TypeSpace3D::AXIS_OX:
		B[1][1] = cos(angleRad);
		B[1][2] = sin(angleRad);
		B[2][1] = -sin(angleRad);
		B[2][2] = cos(angleRad);
		break;
	case TypeSpace3D::AXIS_OY:
		B[0][0] = cos(angleRad);
		B[0][2] = -sin(angleRad);
		B[2][0] = sin(angleRad);
		B[2][2] = cos(angleRad);
		break;
	case TypeSpace3D::AXIS_OZ:
		B[0][0] = cos(angleRad);
		B[0][1] = sin(angleRad);
		B[1][0] = -sin(angleRad);
		B[1][1] = cos(angleRad);
		break;
	}

	double** C = CommonMethod::multiply(A, B, listPoints.size(), 4, 4);
	updatePoints(C);
	return;
}



void Plane3D::rotatePolygon_RotateAnimation(double angle, int axis) {
	double angleRad = PI / 180 * angle;
	double** A = CommonMethod::createPolygonMatrix_3D_RotateAnimation(*this);
	double** B = CommonMethod::createUnitMatrix(3);

	switch (axis) {
	case TypeSpace3D::AXIS_OX:
		B[1][1] = cos(angleRad);
		B[1][2] = sin(angleRad);
		B[2][1] = -sin(angleRad);
		B[2][2] = cos(angleRad);
		break;
	case TypeSpace3D::AXIS_OY:
		B[0][0] = cos(angleRad);
		B[0][2] = -sin(angleRad);
		B[2][0] = sin(angleRad);
		B[2][2] = cos(angleRad);
		break;
	case TypeSpace3D::AXIS_OZ:
		B[0][0] = cos(angleRad);
		B[0][1] = sin(angleRad);
		B[1][0] = -sin(angleRad);
		B[1][1] = cos(angleRad);
		break;
	}

	double** C = CommonMethod::multiply(A, B, listPoints.size(), 4, 4);
	updatePoints(C);
	return;
}

void Plane3D::realRotatePolygon_RotateAnimation( double degree , int axis) {
	rotatePolygon_RotateAnimation(degree, axis);
	cloneListPoints_save();
}


void Plane3D::scalePolygon(double x, double y, double z) {
	double** A = CommonMethod::createPolygonMatrix_3D(*this);
	double** B = CommonMethod::createUnitMatrix(3);

	B[0][0] = x;
	B[1][1] = y;
	B[2][2] = z;

	double** C = CommonMethod::multiply(A, B, listPoints.size(), 4, 4);
	updatePoints(C);
	return;

}

void Plane3D::transformPolygon(double b, double c, double d, double f, double g, double h) {
	double** A = CommonMethod::createPolygonMatrix_3D(*this);
	double** B = CommonMethod::createUnitMatrix(3);

	B[0][1] = b;
	B[0][2] = c;
	B[1][0] = d;
	B[1][2] = f;
	B[2][0] = g;
	B[2][1] = h;

	double** C = CommonMethod::multiply(A, B, listPoints.size(), 4, 4);
	updatePoints(C);
	return;
}


void Plane3D::symmetryPolygon(int type) {
	double** A = CommonMethod::createPolygonMatrix_3D(*this);
	double** B = CommonMethod::createUnitMatrix(3);

	switch (type) {
	case TypeSpace3D::AXIS_OX:
		B[1][1] = -1;
		B[2][2] = -1;
		break;
	case TypeSpace3D::AXIS_OY:
		B[0][0] = -1;
		B[2][2] = -1;
		break;
	case TypeSpace3D::AXIS_OZ:
		B[0][0] = -1;
		B[1][1] = -1;
		break;
	case TypeSpace3D::PLANE_XY:
		B[2][2] = -1;
		break;
	case TypeSpace3D::PLANE_XZ:
		B[1][1] = -1;
		break;
	case TypeSpace3D::PLANE_YZ:
		B[0][0] = -1;
		break;
	}

	double** C = CommonMethod::multiply(A, B, listPoints.size(), 4, 4);
	updatePoints(C);
	return;
}

void Plane3D::movePolygon(double a, double b, double c) {
	double** A = CommonMethod::createPolygonMatrix_3D(*this);
	double** B = CommonMethod::createUnitMatrix(3);
	B[3][0] = a;
	B[3][1] = b;
	B[3][2] = c;

	double** C = CommonMethod::multiply(A, B, listPoints.size(), 4, 4);
	updatePoints(C);
	return;

}