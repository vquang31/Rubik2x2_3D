#include "CommonMethod.h"
#include "Polygon3D.h"

void Polygon3D::draw() {
	
	// draw face
	 
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(redColor, greenColor,  blueColor);

	for (Point3D p : listPoints) {
		glVertex3f(p.x, p.y, p.z);
	}
	glEnd();

	glBegin(GL_LINES);
	glColor3ub(0, 0, 0);

	glVertex3f(listPoints[0].x, listPoints[0].y, listPoints[0].z); // điểm đầu
	glVertex3f(listPoints[3].x, listPoints[3].y, listPoints[3].z);		// điểm cuối



	for (int i = 0; i < 3; i++) {
		glVertex3f(listPoints[i].x, listPoints[i].y, listPoints[i].z); // điểm đầu
		glVertex3f(listPoints[i+1].x, listPoints[i+1].y, listPoints[i+1].z);		// điểm cuối
	}




	glEnd();

	// draw line 


}


void Polygon3D::rotatePolygon(double angel, int axis) {
	double PI = 2 * acos(0.0);
	double angelRad = PI / 180 * angel;
	double** A = CommonMethod::createPolygonMatrix_3D(*this);
	double** B = CommonMethod::createUnitMatrix(3);

	switch (axis) {
	case AXIS_OX:
		B[1][1] = cos(angelRad);
		B[1][2] = sin(angelRad);
		B[2][1] = -sin(angelRad);
		B[2][2] = cos(angelRad);
		break;
	case AXIS_OY:
		B[0][0] = cos(angelRad);
		B[0][2] = -sin(angelRad);
		B[2][0] = sin(angelRad);
		B[2][2] = cos(angelRad);
		break;
	case AXIS_OZ:
		B[0][0] = cos(angelRad);
		B[0][1] = sin(angelRad);
		B[1][0] = -sin(angelRad);
		B[1][1] = cos(angelRad);
		break;
	}

	double** C = CommonMethod::multiply(A, B, listPoints.size(), 4, 4);
	updatePoints(C);
	return;
}

void Polygon3D::scalePolygon(double x, double y, double z) {
	double** A = CommonMethod::createPolygonMatrix_3D(*this);
	double** B = CommonMethod::createUnitMatrix(3);

	B[0][0] = x;
	B[1][1] = y;
	B[2][2] = z;

	double** C = CommonMethod::multiply(A, B, listPoints.size(), 4, 4);
	updatePoints(C);
	return;

}

void Polygon3D::transformPolygon(double b, double c, double d, double f, double g, double h) {
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


void Polygon3D::symmetryPolygon(int type) {
	double** A = CommonMethod::createPolygonMatrix_3D(*this);
	double** B = CommonMethod::createUnitMatrix(3);

	switch (type) {
	case AXIS_OX:
		B[1][1] = -1;
		B[2][2] = -1;
		break;
	case AXIS_OY:
		B[0][0] = -1;
		B[2][2] = -1;
		break;
	case AXIS_OZ:
		B[0][0] = -1;
		B[1][1] = -1;
		break;
	case PLANE_XY:
		B[2][2] = -1;
		break;
	case PLANE_XZ:
		B[1][1] = -1;
		break;
	case PLANE_YZ:
		B[0][0] = -1;
		break;
	}

	double** C = CommonMethod::multiply(A, B, listPoints.size(), 4, 4);
	updatePoints(C);
	return;
}

void Polygon3D::movePolygon(double a, double b, double c) {
	double** A = CommonMethod::createPolygonMatrix_3D(*this);
	double** B = CommonMethod::createUnitMatrix(3);
	B[3][0] = a;
	B[3][1] = b;
	B[3][2] = c;

	double** C = CommonMethod::multiply(A, B, listPoints.size(), 4, 4);
	updatePoints(C);
	return;

}