#include <iostream>
#include "Simple_Image.h"

using namespace cimg_library;

int main()
{
	const unsigned char red[] = { 255,0,0 }, green[] = { 0,255,0 }, blue[] = { 0,0,255 }, black[] = { 0,0,0 }, white[] = { 255,255,255 }, gray[] = {128, 128, 128};

	Simple_Image simple_red(600, 600), simple_green(600, 600), simple_blue(600, 600);

	simple_red.fill(red);
	simple_green.fill(green);
	simple_blue.fill(blue);

	simple_red.save("Red.bmp");
	simple_green.save("Green.bmp");
	simple_blue.save("Blue.bmp");

	//TODO: Create simple_magenta, simple_yellow, simple_cyan
	//	    Using the addition operator, simple_red, simple_blue, and simple_green
	//      Then save them to Magenta.bmp, Yellow.bmp, and Cyan.bmp

	Simple_Image simple_magenta = simple_red + simple_blue;
	Simple_Image simple_yellow = simple_red + simple_green;
	Simple_Image simple_cyan = simple_blue + simple_green;

	simple_magenta.save("Magenta.bmp");
	simple_yellow.save("Yellow.bmp");
	simple_cyan.save("Cyan.bmp");

	//TODO: Create stripes, then use loops and set_point to
	//      fill it as 1/3 red, 1/3 green, and 1/3 blue
	//      save it to Stripes.bmp

	Simple_Image stripes(600, 600);
	for (int x = 0; x < 600; x++) {
		for (int y = 0; y < 200; y++) {
			stripes.set_point(y, x, red);
		}
		for (int z = 200; z < 400; z++) {
			stripes.set_point(z, x, green);
		}
		for (int t = 400; t < 600; t++) {
			stripes.set_point(t, x, blue);
		}

	}
	stripes.save("Stripes.bmp");

	//TODO: Create stripes_red, stripes_green, and stripes_blue
	//      Using the addition operator, stripes, and the three simple primary colors
	//		save them to Red_Stripes.bmp, Green_Stripes.bmp, and Blue_Stripes.bmp
	Simple_Image stripes_red = stripes + simple_red;
	Simple_Image stripes_green = stripes + simple_green;
	Simple_Image stripes_blue = stripes + simple_blue;

	simple_red.save("Red_Stripes.bmp");
	simple_green.save("Green_Stripes.bmp");
	simple_blue.save("Blue_Stripes.bmp");
	//TODO: Create simple_gray, and fill it with gray
	//      Then create faded, assigning it with the subtraction operator
	//      stripes_green, and simple_gray
	//      and save it to Faded_Green_Stripes.bmp

	Simple_Image simple_gray(600, 600);
	simple_gray.fill(gray);

	Simple_Image faded = stripes_green - simple_gray;
	faded.save("faded _Green_Stripes.bmp");

	return 0;
}