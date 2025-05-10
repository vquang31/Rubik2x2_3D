#pragma once

#include "Point3D.h"
#include "Polygon3D.h"

class CommonMethod {
public:
	static double** multiply(double** A, double** B, int x, int y, int z) {
		double** C = new double* [x];
		for (int i = 0; i < x; ++i) {
			C[i] = new double[z];
			for (int j = 0; j < z; ++j) {
				C[i][j] = 0;
				for (int k = 0; k < y; ++k) {
					C[i][j] += A[i][k] * B[k][j];
				}
			}
		}
		return C;
	}


	static double** createPolygonMatrix_3D(Polygon3D p3D) {
		//std::cout << " CREATE" << std::endl;
		int row = p3D.listPoints.size();
		double** A = createEmptyMatrix(row, 3);
		for (int i = 0; i < row; i++) {
			A[i][0] = p3D.listPoints[i].x;
			A[i][1] = p3D.listPoints[i].y;
			A[i][2] = p3D.listPoints[i].z;
			A[i][3] = 1;

			//std::cout << A[i][0] << " " << A[i][1] << " " << A[i][2] << " " << A[i][3] << std:: endl;
		}
		//std::cout << std::endl;

		return A;
	}



	static double** createEmptyMatrix(int row, int dimension) {
		double** A = new double* [row];
		for (int i = 0; i < row; i++) {
			A[i] = new double[dimension + 1];
			for (int j = 0; j < dimension + 1; j++) {
				A[i][j] = 0;
			}
		}
		return A;
	}
	static double** createUnitMatrix(int dimension) {
		double** A = new double* [dimension + 1];
		for (int i = 0; i < dimension + 1; i++) {
			A[i] = new double[dimension + 1];
			for (int j = 0; j < dimension + 1; j++) {
				A[i][j] = 0;
			}
			A[i][i] = 1;
		}
		return A;
	}

};
