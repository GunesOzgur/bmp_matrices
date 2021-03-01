/* main.c
 *
 * A module of "bmp_matrices" project.
 *
 * "bmp_matrices" enables to make modifications
 * on bitmap images by means of matrices.
 *
 * Last modified on March 01, 2021.
 *
 * by Freeman Sun.
 * GitHub: https://github.com/GunesOzgur
*/

#include "bmp_matrices.h"

int main(int argc, char** argv)
{
	// Detect bmp_height and bmp_width
	detect_bmp_dimentions(argv[1]);
	
	printf("width: %d\n", bmp_width);
	printf("height: %d\n", bmp_height);
	
	// RGB matrices
	uint8_t red[bmp_height][bmp_width];
	uint8_t green[bmp_height][bmp_width];
	uint8_t blue[bmp_height][bmp_width];
	
	// Scan RGM matrices from the console input file
	bmp2mat(argv[1], red, green, blue);
	
	printf("data adress: %d\n", bmp_data_adress);
	printf("data size: %d\n", bmp_data_size);
	
	// Print matrices on "test.bmp"
	mat2bmp(red, green, blue, "test.bmp");
	
	return 0;
} // main()