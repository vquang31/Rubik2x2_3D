#pragma once

#include "Polygon3D.h"
#include "Cube.h"
#include <array>

class RubikCube {

	////
	//R, 2 === L`,1
	//1Y1 -> 1Yn
	//1Yn -> nYn
	//nYn -> nY1
	//nY1 -> 1Y1
	//R`,2 === L, 1
	//1Y1 <- 1Yn
	//1Yn <- nYn
	//nYn <- nY1
	//nY1 <- 1Y1
	//F, 1 === B`,2
	//X11 -> X1n
	//X1n -> Xnn
	//Xnn -> Xn1
	//Xn1 -> X11
	//F`, 1 === B, 2
	//X11 <- X1n
	//X1n <- Xnn
	//Xnn <- Xn1
	//Xn1 <- X11
	//D, 1 === U`,2
	//11|Z -> 1n|Z
	//1n|Z -> nn|Z
	//nn|Z -> n1|Z
	//n1|Z -> 11|Z
	//D`,1 === U, 2
	//11|Z <- 1n|Z
	//1n|Z <- nn|Z
	//nn|Z <- n1|Z
	//n1|Z <- 11|Z

public :


	Cube cube[8];

	// red đối yellow
	// green đối blue 
	// white đối black


	RubikCube() {
		cube[0].update(1, 1, 1);
		cube[1].update(1, 1, 2);
		cube[2].update(1, 2, 1);
		cube[3].update(1, 2, 2);
		cube[4].update(2, 1, 1);
		cube[5].update(2, 1, 2);
		cube[6].update(2, 2, 1);
		cube[7].update(2, 2, 2);


		cube[0].face[0].updateColor(Polygon3D::COLOR_RED);			// red
		cube[0].face[1].updateColor(Polygon3D::COLOR_GREEN);		// green
		cube[0].face[2].updateColor(Polygon3D::COLOR_BLACK);		// black

		cube[1].face[0].updateColor(Polygon3D::COLOR_YELLOW);		// yellow
		cube[1].face[1].updateColor(Polygon3D::COLOR_GREEN);		// green
		cube[1].face[2].updateColor(Polygon3D::COLOR_BLACK);		// black

		cube[2].face[0].updateColor(Polygon3D::COLOR_RED);			// red
		cube[2].face[1].updateColor(Polygon3D::COLOR_GREEN);		// green
		cube[2].face[2].updateColor(Polygon3D::COLOR_WHITE);		// white

		cube[3].face[0].updateColor(Polygon3D::COLOR_YELLOW);		// yelloW
		cube[3].face[1].updateColor(Polygon3D::COLOR_GREEN);		// green
		cube[3].face[2].updateColor(Polygon3D::COLOR_WHITE);		// white

		cube[4].face[0].updateColor(Polygon3D::COLOR_RED);			// red
		cube[4].face[1].updateColor(Polygon3D::COLOR_BLUE);			// blue
		cube[4].face[2].updateColor(Polygon3D::COLOR_BLACK);		// black	

		cube[5].face[0].updateColor(Polygon3D::COLOR_YELLOW);		// yello
		cube[5].face[1].updateColor(Polygon3D::COLOR_BLUE);			// blue
		cube[5].face[2].updateColor(Polygon3D::COLOR_BLACK);		// black

		cube[6].face[0].updateColor(Polygon3D::COLOR_RED);			// red
		cube[6].face[1].updateColor(Polygon3D::COLOR_BLUE);			// blue
		cube[6].face[2].updateColor(Polygon3D::COLOR_WHITE);		// white

		cube[7].face[0].updateColor(Polygon3D::COLOR_YELLOW);		// yellow
		cube[7].face[1].updateColor(Polygon3D::COLOR_BLUE);			// blue
		cube[7].face[2].updateColor(Polygon3D::COLOR_WHITE);		// white

		cube[0].face[0].update({ {0 , 0, -1 }, { -1, 0, -1 }, { -1, -1, -1 }, { 0, -1, -1 } } );
		cube[0].face[1].update({ {-1, 0, -1 }, { -1, 0, 0 }, { -1, -1, 0 }, { -1, -1, -1 } } );
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







		randomRotate();
	}

	void draw() {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 3; j++) {
				cube[i].face[j].draw();
			}
		}
	}


protected:


	void randomRotate(){
	
	}




private:



};
