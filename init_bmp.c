/* detect_bmp_dimentions.c
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

void init_bmp(uint32_t width, uint32_t height)
{
	// Initilizes BMP chucks with standard values.
	// Useful while creating a BMP from scratch.
	
	// Arguments:
	// width -> width value of BMP to create.
	// height -> height value of BMP to create.
	
	// Set variable values
	bmp_width = width; // Bytes 18-21
	bmp_height = height; // Bytes 22-25
	bmp_data_size = ((width*3)+(width%4))*height; // Bytes 34-37
	bmp_total_size = bmp_data_size + bmp_data_adress; // Bytes 2-9
	
	bmp_header = 0x4D42; // Bytes 0-1
	bmp_data_adress = 0x00000036; // Bytes 10-13
	bmp_CoreHeader_size = 0x00000028; // Bytes 14-17
	bmp_color_planes = 0x0001; // Bytes 26-27
	bmp_bit_per_pixel = 0x0018; // Bytes 28-29
	bmp_compression_method = 0x00000000; // Bytes 30-33
	bmp_horizontal_resolution = 0x00000000; // Bytes 38-41
	bmp_vertical_resolution = 0x00000000; // Bytes 42-45
	bmp_num_of_colors_in_palette = 0x00000000; // Bytes 46-49
	bmp_num_of_important_colors = 0x00000000; // Bytes 50-54
	
} // init_bmp()