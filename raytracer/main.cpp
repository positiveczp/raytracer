#include <stdlib.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include "math.h"

void render() {
	const int width = 200;
	const int height = 100;
	std::vector<Vec3f> framebuffer(width * height);

	for (size_t j = 0; j < height; j++) {
		for (size_t i = 0; i < width; i++) {
			framebuffer[i + j * width] = Vec3f(i / float(width), j / float(height), 0);
		}
	}

	std::ofstream ofs;
	ofs.open("../out.ppm");
	ofs << "P3\n" << width << " " << height << "\n255\n";
	for (size_t i = 0; i < height * width; ++i) {
		int r = 255 * framebuffer[i][0];
		int g = 255 * framebuffer[i][1];
		int b = 255 * framebuffer[i][2];
		ofs << r << " " << g << " " << b << std::endl;
	}
	ofs.close();
}


int main() {
	render();
	return 0;
}




