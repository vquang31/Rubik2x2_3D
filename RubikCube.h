#pragma once

#include "Polygon3D.h"
#include "Cube.h"
#include <array>
#include "TypeRotate.h"
class RubikCube {

public :



	void Rotate(int type);

	////
	//R, 2 === L`,1
	//11Z -> 1nZ
	//1nZ -> nnZ
	//nnZ -> n1Z
	//n1Z -> 11Z
	//R`,2 === L, 1
	//11Z <- 1nZ
	//1nZ <- nnZ
	//nnZ <- n1Z
	//n1Z <- 11Z
	//F, 1 === B`,2
	//X11 -> Xn1
	//Xn1 -> Xnn
	//Xnn -> X1n
	//X1n -> X11
	//F`, 1 === B, 2
	//X11 <- Xn1
	//Xn1 <- Xnn
	//Xnn <- X1n
	//X1n <- X11
	//D, 1 === U`,2
	//1Y1 -> 1Yn
	//1Yn -> nYn
	//nYn -> nY1
	//nY1 -> 1Y1
	//D`,1 === U, 2
	//1Y1 <- 1Yn
	//1Yn <- nYn
	//nYn <- nY1
	//nY1 <- 1Y1



	Cube cube[8];

	Cube* FindCube(int x, int y, int z) {
		for (int i = 0; i < 8; i++) {
			if (cube[i].moving == false && cube[i].position.x == x && cube[i].position.y == y && cube[i].position.z == z) {
				return &cube[i];
			}
		}

		return &cube[0];
	}

	void inCube() {
		for (int i = 0; i < 8; i++) {
			std::cout << "Cube " << i << ": " << cube[i].position.x << " " << cube[i].position.y << " " << cube[i].position.z << std::endl;
		}
	}


	// red đối yellow
	// green đối blue 
	// white đối ORANGE


	void initPosition() {
		cube[0].updatePosition(1, 1, 1);
		cube[1].updatePosition(1, 1, 2);
		cube[2].updatePosition(1, 2, 1);
		cube[3].updatePosition(1, 2, 2);
		cube[4].updatePosition(2, 1, 1);
		cube[5].updatePosition(2, 1, 2);
		cube[6].updatePosition(2, 2, 1);
		cube[7].updatePosition(2, 2, 2);
	}
	void initColor() {
		cube[0].face[0].updateColor(Polygon3D::COLOR_RED);			// red
		cube[0].face[1].updateColor(Polygon3D::COLOR_GREEN);		// green
		cube[0].face[2].updateColor(Polygon3D::COLOR_ORANGE);		// orange

		cube[1].face[0].updateColor(Polygon3D::COLOR_YELLOW);		// yellow
		cube[1].face[1].updateColor(Polygon3D::COLOR_GREEN);		// green
		cube[1].face[2].updateColor(Polygon3D::COLOR_ORANGE);		// orange

		cube[2].face[0].updateColor(Polygon3D::COLOR_RED);			// red
		cube[2].face[1].updateColor(Polygon3D::COLOR_GREEN);		// green
		cube[2].face[2].updateColor(Polygon3D::COLOR_WHITE);		// white

		cube[3].face[0].updateColor(Polygon3D::COLOR_YELLOW);		// yelloW
		cube[3].face[1].updateColor(Polygon3D::COLOR_GREEN);		// green
		cube[3].face[2].updateColor(Polygon3D::COLOR_WHITE);		// white

		cube[4].face[0].updateColor(Polygon3D::COLOR_RED);			// red
		cube[4].face[1].updateColor(Polygon3D::COLOR_BLUE);			// blue
		cube[4].face[2].updateColor(Polygon3D::COLOR_ORANGE);		// orange	

		cube[5].face[0].updateColor(Polygon3D::COLOR_YELLOW);		// yello
		cube[5].face[1].updateColor(Polygon3D::COLOR_BLUE);			// blue
		cube[5].face[2].updateColor(Polygon3D::COLOR_ORANGE);		// orange

		cube[6].face[0].updateColor(Polygon3D::COLOR_RED);			// red
		cube[6].face[1].updateColor(Polygon3D::COLOR_BLUE);			// blue
		cube[6].face[2].updateColor(Polygon3D::COLOR_WHITE);		// white

		cube[7].face[0].updateColor(Polygon3D::COLOR_YELLOW);		// yellow
		cube[7].face[1].updateColor(Polygon3D::COLOR_BLUE);			// blue
		cube[7].face[2].updateColor(Polygon3D::COLOR_WHITE);		// white

	}
	void initFaces() {
		cube[0].face[0].update({ {0 , 0, -1 }, { -1, 0, -1 }, { -1, -1, -1 }, { 0, -1, -1 } });
		cube[0].face[1].update({ {-1, 0, -1 }, { -1, 0, 0 }, { -1, -1, 0 }, { -1, -1, -1 } });
		cube[0].face[2].update({ {-1, -1, -1 }, { 0, -1, -1 }, { 0, -1, 0 }, { -1, -1, 0 } });

		cube[1].face[0].update({ {-1, -1, 1}, { 0, -1, 1}, {0, 0,  1 }, { -1, 0, 1} });
		cube[1].face[1].update({ { -1, 0, 1}, { -1, 0, 0}, {-1, -1, 0 }, { -1, -1, 1} });
		cube[1].face[2].update({ { -1, -1, 1}, { -1, -1, 0}, { 0, -1, 0}, { 0, -1, 1} });

		cube[2].face[0].update({ {-1, 1, -1}, {-1, 0, -1}, {0, 0, -1},  {0, 1, -1} });
		cube[2].face[1].update({ {-1, 1, -1}, {-1, 1, 0}, {-1, 0, 0},  {-1, 0, -1} });
		cube[2].face[2].update({ {-1, 1, -1}, {-1, 1, 0}, {0, 1, 0},  {0, 1, -1} });

		cube[3].face[0].update({ {-1, 1, 1}, {0, 1, 1}, {0, 0, 1},  {-1, 0, 1} }); //y
		cube[3].face[1].update({ {-1, 1, 1}, {-1, 1, 0}, {-1, 0, 0},  {-1, 0, 1} });// g	
		cube[3].face[2].update({ {-1, 1, 1}, {0, 1, 1}, {0, 1, 0}, {-1, 1, 0} });// b

		cube[4].face[0].update({ {1, -1, -1}, {1, 0, -1}, {0, 0, -1},  {0, -1, -1} }); //r
		cube[4].face[1].update({ {1, -1, -1}, {1, -1, 0}, {1, 0, 0},  {1, 0, -1} }); //b
		cube[4].face[2].update({ {1, -1, -1}, {1, -1, 0}, {0, -1, 0},  {0, -1, -1} }); //b

		cube[5].face[0].update({ {1, -1, 1}, {1, 0, 1}, {0, 0, 1}, {0, -1, 1} }); //y
		cube[5].face[1].update({ {1, -1, 1}, {1, -1, 0}, {1, 0, 0}, {1, 0, 1} }); //b
		cube[5].face[2].update({ {1, -1, 1}, {1, -1, 0}, {0, -1, 0}, {0, -1, 1} }); //b

		cube[6].face[0].update({ {1, 1, -1}, {0, 1, -1}, {0, 0, -1}, {1, 0, -1} }); //r
		cube[6].face[1].update({ {1, 1, -1}, {1, 1, 0}, {1, 0, 0}, {1, 0, -1} }); //b
		cube[6].face[2].update({ {1, 1, -1}, {0, 1, -1}, {0, 1, 0}, {1, 1, 0} }); //w

		cube[7].face[0].update({ {1, 1, 1}, {0, 1, 1}, {0, 0, 1}, {1, 0, 1} }); //y
		cube[7].face[1].update({ {1, 1, 1}, {1, 1, 0}, {1, 0, 0}, {1, 0, 1} }); //b
		cube[7].face[2].update({ {1, 1, 1}, {1, 1, 0}, {0, 1, 0}, {0, 1, 1} }); //w

	}
	void randomRotate(){
		int n = 10;
		for (int i = 0; i < n; i++) {
			int type = rand() % 12 + 1;
			Rotate(type);
		}
	}



	RubikCube() {
		initPosition();
		initColor();
		initFaces();

		//randomRotate();
	}

	void draw() {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 3; j++) {
				cube[i].draw();
			}
		}
	}



protected:

	void resetMoving() {
		for (int i = 0; i < 8; i++) {
			cube[i].resetMovingFalse();
		}
	}


private:



};
