#pragma once

class Position3D {

public:
	int x = 0;
	int y = 0;
	int z = 0;

	Position3D(int x, int y, int z) : x(x), y(y), z(z) {}
	Position3D() {
		x = 0;
		y = 0;
		z = 0;
	}
};
