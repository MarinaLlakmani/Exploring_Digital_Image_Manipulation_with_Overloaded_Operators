#include "Simple_Image.h"

Simple_Image::Simple_Image(int x, int y) : x(x), y(y) {
	pixels = new unsigned char** [x];
	for (int i = 0; i < x; ++i) {
		pixels[i] = new unsigned char* [y];
		for (int j = 0; j < y; ++j) {
			pixels[i][j] = new unsigned char[3];
			pixels[i][j][0] = 0;
			pixels[i][j][1] = 0;
			pixels[i][j][2] = 0;
		}
	}
}

Simple_Image::~Simple_Image() {
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			delete[] pixels[i][j];
		}
		delete[] pixels[i];
	}
	delete[] pixels;
}

void Simple_Image::fill(const unsigned char color[]) {
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; j++) {
			set_point(i, j, color);
		}
	}

}

void Simple_Image::set_point(int x, int y, const unsigned char color[]) {
	pixels[x][y][0] = color[0];
	pixels[x][y][1] = color[1];
	pixels[x][y][2] = color[2];
}

Simple_Image Simple_Image::operator+(const Simple_Image& other) const {
	Simple_Image result(x, y);
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			for (int e = 0; e < 3; e++) {
				int val = static_cast<int>(pixels[i][j][e]) + static_cast<int>(other.pixels[i][j][e]);
				result.pixels[i][j][e] = val > 255 ? 255 : static_cast<unsigned char>(val);
			}
		}
	}

	return result;

}

Simple_Image Simple_Image::operator-(const Simple_Image& other) const {
	Simple_Image result(x, y);
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			for (int e = 0; e < 3; e++) {
				int val = static_cast<int>(pixels[i][j][e]) - static_cast<int>(other.pixels[i][j][e]);
				result.pixels[i][j][e] = val < 0 ? 0 : static_cast<unsigned char>(val);
			}
		}
	}
	return result;
}

CImg<unsigned char> Simple_Image::toCImg() {
	CImg<unsigned char> res(x, y, 1, 3, 0);
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			res(i, j, 0) = pixels[i][j][0];
			res(i, j, 1) = pixels[i][j][1];
			res(i, j, 2) = pixels[i][j][2];
		}
	}
	return res;
}

void Simple_Image::save(const char* filename) {
	this->toCImg().save(filename);
}

void Simple_Image::display() {
	CImgDisplay disp(this->toCImg(), "Simple Image");
	while (!disp.is_closed()) {
		disp.wait();
	}
}

