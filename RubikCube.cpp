#include "RubikCube.h"
#include <iostream>

void RubikCube::Rotate(int type) {

	int n = 2;
	int X = 1;
	int Y = 1;
	int Z = 1;
	switch (type) {
		case TypeRotate::TYPE_L_:
		case TypeRotate::TYPE_R:
			if (type == TypeRotate::TYPE_R)
				Z = 2;
		
			FindCube(1, 1, Z)->rotateAndUpdatePosition(1, n, Z, TypeRotate::TYPE_R);
			FindCube(1, n, Z)->rotateAndUpdatePosition(n, n, Z, TypeRotate::TYPE_R);
			FindCube(n, n, Z)->rotateAndUpdatePosition(n, 1, Z, TypeRotate::TYPE_R);
			FindCube(n, 1, Z)->rotateAndUpdatePosition(1, 1, Z, TypeRotate::TYPE_R);

			resetMoving();
			break;

		case TypeRotate::TYPE_L:
		case TypeRotate::TYPE_R_:
			if (type == TypeRotate::TYPE_R_)
				Z = 2;
			FindCube(1, 1, Z)->rotateAndUpdatePosition(n, 1, Z, TypeRotate::TYPE_R_);
			FindCube(n, 1, Z)->rotateAndUpdatePosition(n, n, Z, TypeRotate::TYPE_R_);
			FindCube(n, n, Z)->rotateAndUpdatePosition(1, n, Z, TypeRotate::TYPE_R_);
			FindCube(1, n, Z)->rotateAndUpdatePosition(1, 1, Z, TypeRotate::TYPE_R_);

			resetMoving();
			break;

		///////////////////////
		case TypeRotate::TYPE_F:
		case TypeRotate::TYPE_B_:
			if (type == TypeRotate::TYPE_B_)
				X = 2;
			FindCube(X, 1, 1)->rotateAndUpdatePosition(X, n, 1, TypeRotate::TYPE_B_);
			FindCube(X, n, 1)->rotateAndUpdatePosition(X, n, n, TypeRotate::TYPE_B_);
			FindCube(X, n, n)->rotateAndUpdatePosition(X, 1, n, TypeRotate::TYPE_B_);
			FindCube(X, 1, n)->rotateAndUpdatePosition(X, 1, 1, TypeRotate::TYPE_B_);

			resetMoving();
			break;

		case TypeRotate::TYPE_F_:
		case TypeRotate::TYPE_B:
			if (type == TypeRotate::TYPE_B)
				X = 2;
			FindCube(X, 1, 1)->rotateAndUpdatePosition(X, 1, n, TypeRotate::TYPE_B);
			FindCube(X, 1, n)->rotateAndUpdatePosition(X, n, n, TypeRotate::TYPE_B);
			FindCube(X, n, n)->rotateAndUpdatePosition(X, n, 1, TypeRotate::TYPE_B);
			FindCube(X, n, 1)->rotateAndUpdatePosition(X, 1, 1, TypeRotate::TYPE_B);

			resetMoving();
			break;

			///////////////////////
		case TypeRotate::TYPE_D:
		case TypeRotate::TYPE_U_:
			if (type == TypeRotate::TYPE_U_)
				Y = 2;

			FindCube(1, Y, 1)->rotateAndUpdatePosition(1, Y, n, TypeRotate::TYPE_U_);
			FindCube(1, Y, n)->rotateAndUpdatePosition(n, Y, n, TypeRotate::TYPE_U_);
			FindCube(n, Y, n)->rotateAndUpdatePosition(n, Y, 1, TypeRotate::TYPE_U_);
			FindCube(n, Y, 1)->rotateAndUpdatePosition(1, Y, 1, TypeRotate::TYPE_U_);

			resetMoving();
			break;
		case TypeRotate::TYPE_D_:
		case TypeRotate::TYPE_U:
			if(type == TypeRotate::TYPE_U)
				Y = 2;

			FindCube(1, Y, 1)->rotateAndUpdatePosition(n, Y, 1, TypeRotate::TYPE_U); // TYPE_D_ như nhau
			FindCube(n, Y, 1)->rotateAndUpdatePosition(n, Y, n, TypeRotate::TYPE_U);
			FindCube(n, Y, n)->rotateAndUpdatePosition(1, Y, n, TypeRotate::TYPE_U);
			FindCube(1, Y, n)->rotateAndUpdatePosition(1, Y, 1, TypeRotate::TYPE_U);

			resetMoving();
			break;
	}


}