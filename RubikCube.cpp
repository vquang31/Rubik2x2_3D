#include "RubikCube.h"
#include <iostream>

void RubikCube::rotate(int type) {

	if (rotating) return;	
	rotating = true;
	startRotateTime = glutGet(GLUT_ELAPSED_TIME);
	typeRotate = type;
}

void RubikCube::rotate_Animation() {
	if (rotating == false) return;
	int now = glutGet(GLUT_ELAPSED_TIME);
	double angle;
	if (now < startRotateTime + ROTATE_TIME) {
		angle = (double)(now - startRotateTime) / ROTATE_TIME * 90;
	}
	else {
		rotating = false;
		angle = 90;
		switch (typeRotate) {
		case TypeRotate::TYPE_R: 
			std::cout << "TYPE_R" << std::endl;
			break;
		case TypeRotate::TYPE_R_:
			std::cout << "TYPE_R_" << std::endl;
			break;
		case TypeRotate::TYPE_L :
			std::cout << "TYPE_L" << std::endl;
			break;
		case TypeRotate::TYPE_L_:
			std::cout << "TYPE_L_" << std::endl;
			break;
		case TypeRotate::TYPE_F :
			std::cout << "TYPE_F" << std::endl;
			break;
		case TypeRotate::TYPE_F_:
			std::cout << "TYPE_F_" << std::endl;
			break;
		case TypeRotate::TYPE_B :
			std::cout << "TYPE_B" << std::endl;
			break;
		case TypeRotate::TYPE_B_:
			std::cout << "TYPE_B_" << std::endl;
			break;
		case TypeRotate::TYPE_U :
			std::cout << "TYPE_U" << std::endl;
			break;
		case TypeRotate::TYPE_U_:
			std::cout << "TYPE_U_" << std::endl;
			break;
		case TypeRotate::TYPE_D :
			std::cout << "TYPE_D" << std::endl;
			break;
		case TypeRotate::TYPE_D_:
			std::cout << "TYPE_D_" << std::endl;
			break;

		}
	}

	int n = 2;
	int X = 1;
	int Y = 1;
	int Z = 1;

	int type = typeRotate;
	switch (type) {
		case TypeRotate::TYPE_L_:
		case TypeRotate::TYPE_R:
			if (type == TypeRotate::TYPE_R)
				Z = 2;

			FindCube(1, 1, Z)->rotateAndUpdatePosition(1, n, Z, TypeRotate::TYPE_R, angle);
			FindCube(1, n, Z)->rotateAndUpdatePosition(n, n, Z, TypeRotate::TYPE_R, angle);
			FindCube(n, n, Z)->rotateAndUpdatePosition(n, 1, Z, TypeRotate::TYPE_R, angle);
			FindCube(n, 1, Z)->rotateAndUpdatePosition(1, 1, Z, TypeRotate::TYPE_R, angle);

			resetMoving();
			break;

		case TypeRotate::TYPE_L:
		case TypeRotate::TYPE_R_:
			if (type == TypeRotate::TYPE_R_)
				Z = 2;
			FindCube(1, 1, Z)->rotateAndUpdatePosition(n, 1, Z, TypeRotate::TYPE_R_, angle);
			FindCube(n, 1, Z)->rotateAndUpdatePosition(n, n, Z, TypeRotate::TYPE_R_, angle);
			FindCube(n, n, Z)->rotateAndUpdatePosition(1, n, Z, TypeRotate::TYPE_R_, angle);
			FindCube(1, n, Z)->rotateAndUpdatePosition(1, 1, Z, TypeRotate::TYPE_R_, angle);

			resetMoving();
			break;

			///////////////////////
		case TypeRotate::TYPE_F:
		case TypeRotate::TYPE_B_:
			if (type == TypeRotate::TYPE_B_)
				X = 2;
			FindCube(X, 1, 1)->rotateAndUpdatePosition(X, n, 1, TypeRotate::TYPE_B_, angle);
			FindCube(X, n, 1)->rotateAndUpdatePosition(X, n, n, TypeRotate::TYPE_B_, angle);
			FindCube(X, n, n)->rotateAndUpdatePosition(X, 1, n, TypeRotate::TYPE_B_, angle);
			FindCube(X, 1, n)->rotateAndUpdatePosition(X, 1, 1, TypeRotate::TYPE_B_, angle);

			resetMoving();
			break;

		case TypeRotate::TYPE_F_:
		case TypeRotate::TYPE_B:
			if (type == TypeRotate::TYPE_B)
				X = 2;
			FindCube(X, 1, 1)->rotateAndUpdatePosition(X, 1, n, TypeRotate::TYPE_B, angle);
			FindCube(X, 1, n)->rotateAndUpdatePosition(X, n, n, TypeRotate::TYPE_B, angle);
			FindCube(X, n, n)->rotateAndUpdatePosition(X, n, 1, TypeRotate::TYPE_B, angle);
			FindCube(X, n, 1)->rotateAndUpdatePosition(X, 1, 1, TypeRotate::TYPE_B, angle);

			resetMoving();
			break;

			///////////////////////
		case TypeRotate::TYPE_D:
		case TypeRotate::TYPE_U_:
			if (type == TypeRotate::TYPE_U_)
				Y = 2;

			FindCube(1, Y, 1)->rotateAndUpdatePosition(1, Y, n, TypeRotate::TYPE_U_, angle);
			FindCube(1, Y, n)->rotateAndUpdatePosition(n, Y, n, TypeRotate::TYPE_U_, angle);
			FindCube(n, Y, n)->rotateAndUpdatePosition(n, Y, 1, TypeRotate::TYPE_U_, angle);
			FindCube(n, Y, 1)->rotateAndUpdatePosition(1, Y, 1, TypeRotate::TYPE_U_, angle);

			resetMoving();
			break;
		case TypeRotate::TYPE_D_:
		case TypeRotate::TYPE_U:
			if (type == TypeRotate::TYPE_U)
				Y = 2;

			FindCube(1, Y, 1)->rotateAndUpdatePosition(n, Y, 1, TypeRotate::TYPE_U, angle); // TYPE_D_ như nhau
			FindCube(n, Y, 1)->rotateAndUpdatePosition(n, Y, n, TypeRotate::TYPE_U, angle);
			FindCube(n, Y, n)->rotateAndUpdatePosition(1, Y, n, TypeRotate::TYPE_U, angle);
			FindCube(1, Y, n)->rotateAndUpdatePosition(1, Y, 1, TypeRotate::TYPE_U, angle);

			resetMoving();
			break;
	}
	

	///
	if (!randomRotateTypeQueue.empty()) {
		if (rotating == true) return;
		rotate(randomRotateTypeQueue.front());
		randomRotateTypeQueue.pop();
	}

}

void RubikCube::randomRotate() {
	std::cout << "RandomRotate:" << std::endl;
	int n = 10;
	for (int i = 0; i < n; i++) {
		int type = rand() % 12 + 1;
		randomRotateTypeQueue.push(type);
	}
	rotate(randomRotateTypeQueue.front());
}

void RubikCube::draw() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 3; j++) {
			cube[i].draw();
		}
	}
}