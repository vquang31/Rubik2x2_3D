#pragma once
#include <GL/glut.h>
#include <gl/GL.h>
#include "Plane3D.h"
class Button : public Plane3D{
public:

	int typeRotate = -1;

	Button(std::vector<Point3D> listPoints1 , int typeRotate , int typeColor){
		Plane3D::update(listPoints1);
		this->typeRotate = typeRotate;
		this->updateColor(typeColor);
	}


	bool hit(const Point3D& origin, const Point3D& dir) const {
		if (listPoints.size() < 3) return false;

		Point3D p0 = listPoints[0];
		Point3D edge1 = listPoints[1] - listPoints[0];
		Point3D edge2 = listPoints[2] - listPoints[0];
		Point3D normal = edge1.cross(edge2);

		float denom = normal.dot(dir);
		if (std::abs(denom) < 1e-6) return false;

		float t = normal.dot(p0 - origin) / denom;
		if (t < 0) return false;

		Point3D hitPoint = { origin.x + dir.x * t, origin.y + dir.y * t, origin.z + dir.z * t };

		// Point-in-polygon test using winding number (for convex polygons)
		int n = listPoints.size();
		for (int i = 0; i < n; ++i) {
			Point3D a = listPoints[i];
			Point3D b = listPoints[(i + 1) % n];
			Point3D edge = b - a;
			Point3D toPoint = hitPoint - a;
			if (normal.dot(edge.cross(toPoint)) < 0) return false;
		}
		return true;
	}

};
