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

int mat2bmp(
	uint8_t R_m[bmp_height][bmp_width],
	uint8_t G_m[bmp_height][bmp_width],
	uint8_t B_m[bmp_height][bmp_width],
	char* bmpName)
{
	// Transfer the data from GB matrices into the BMP file.
	
	// Arguments:
	// R_m -> RED Channel Matrix.
	// G_m -> GREEN Channel Matrix.
	// B_m -> BLUE Channel Matrix.
	// bmpName -> name for the BMP that will be created.
	
	// bmp_height & bmp_width are grobal variables.
	
	FILE *fPtr;
	
	if( (fPtr = fopen(bmpName, "wb")) == NULL ) {

		MessageBox(0, bmpName, "Not opened!",
			MB_ICONEXCLAMATION | MB_OK | MB_SYSTEMMODAL);
		
		return -1;
	}
	
	uint8_t Byte;
	uint64_t longInt;
	
	// Print bmp_header
	longInt = 0x4D42;
	Byte = longInt;
	fprintf(fPtr, "%c", Byte); // Byte 0
	Byte = longInt>>8;
	fprintf(fPtr, "%c", Byte); // Byte 1
	
	// Print bmp_total_size
	longInt = bmp_total_size;
	Byte = longInt;
	fprintf(fPtr, "%c", Byte); // Byte 2
	Byte = longInt>>8;
	fprintf(fPtr, "%c", Byte); // Byte 3
	Byte = longInt>>16;
	fprintf(fPtr, "%c", Byte); // Byte 4
	Byte = longInt>>24;
	fprintf(fPtr, "%c", Byte); // Byte 5
	Byte = longInt>>32;
	fprintf(fPtr, "%c", Byte); // Byte 6
	Byte = longInt>>40;
	fprintf(fPtr, "%c", Byte); // Byte 7
	Byte = longInt>>48;
	fprintf(fPtr, "%c", Byte); // Byte 8
	Byte = longInt>>56;
	fprintf(fPtr, "%c", Byte); // Byte 9
	
	// Print bmp_data_adress
	longInt = bmp_data_adress;
	Byte = longInt;
	fprintf(fPtr, "%c", Byte); // Byte 10
	Byte = longInt>>8;
	fprintf(fPtr, "%c", Byte); // Byte 11
	Byte = longInt>>16;
	fprintf(fPtr, "%c", Byte); // Byte 12
	Byte = longInt>>24;
	fprintf(fPtr, "%c", Byte); // Byte 13
	
	// Print bmp_CoreHeader_size
	longInt = bmp_CoreHeader_size;
	Byte = longInt;
	fprintf(fPtr, "%c", Byte); // Byte 14
	Byte = longInt>>8;
	fprintf(fPtr, "%c", Byte); // Byte 15
	Byte = longInt>>16;
	fprintf(fPtr, "%c", Byte); // Byte 16
	Byte = longInt>>24;
	fprintf(fPtr, "%c", Byte); // Byte 17
	
	// Print bmp_width
	longInt = bmp_width;
	Byte = longInt;
	fprintf(fPtr, "%c", Byte); // Byte 18
	Byte = longInt>>8;
	fprintf(fPtr, "%c", Byte); // Byte 19
	Byte = longInt>>16;
	fprintf(fPtr, "%c", Byte); // Byte 20
	Byte = longInt>>24;
	fprintf(fPtr, "%c", Byte); // Byte 21
	
	// Print bmp_height
	longInt = bmp_height;
	Byte = longInt;
	fprintf(fPtr, "%c", Byte); // Byte 22
	Byte = longInt>>8;
	fprintf(fPtr, "%c", Byte); // Byte 23
	Byte = longInt>>16;
	fprintf(fPtr, "%c", Byte); // Byte 24
	Byte = longInt>>24;
	fprintf(fPtr, "%c", Byte); // Byte 25
	
	// Print bmp_color_planes
	longInt = bmp_color_planes;
	Byte = longInt;
	fprintf(fPtr, "%c", Byte); // Byte 26
	Byte = longInt>>8;
	fprintf(fPtr, "%c", Byte); // Byte 27
	
	// Print bmp_bit_per_pixel
	longInt = bmp_bit_per_pixel;
	Byte = longInt;
	fprintf(fPtr, "%c", Byte); // Byte 28
	Byte = longInt>>8;
	fprintf(fPtr, "%c", Byte); // Byte 29
	
	// Print bmp_compression_method
	longInt = bmp_compression_method;
	Byte = longInt;
	fprintf(fPtr, "%c", Byte); // Byte 30
	Byte = longInt>>8;
	fprintf(fPtr, "%c", Byte); // Byte 31
	Byte = longInt>>16;
	fprintf(fPtr, "%c", Byte); // Byte 32
	Byte = longInt>>24;
	fprintf(fPtr, "%c", Byte); // Byte 33
	
	// Print bmp_data_size
	longInt = bmp_data_size;
	Byte = longInt;
	fprintf(fPtr, "%c", Byte); // Byte 34
	Byte = longInt>>8;
	fprintf(fPtr, "%c", Byte); // Byte 35
	Byte = longInt>>16;
	fprintf(fPtr, "%c", Byte); // Byte 36
	Byte = longInt>>24;
	fprintf(fPtr, "%c", Byte); // Byte 37
	
	// Print bmp_horizontal_resolution
	longInt = bmp_horizontal_resolution;
	Byte = longInt;
	fprintf(fPtr, "%c", Byte); // Byte 38
	Byte = longInt>>8;
	fprintf(fPtr, "%c", Byte); // Byte 39
	Byte = longInt>>16;
	fprintf(fPtr, "%c", Byte); // Byte 40
	Byte = longInt>>24;
	fprintf(fPtr, "%c", Byte); // Byte 41
	
	// Print bmp_vertical_resolution
	longInt = bmp_vertical_resolution;
	Byte = longInt;
	fprintf(fPtr, "%c", Byte); // Byte 42
	Byte = longInt>>8;
	fprintf(fPtr, "%c", Byte); // Byte 43
	Byte = longInt>>16;
	fprintf(fPtr, "%c", Byte); // Byte 44
	Byte = longInt>>24;
	fprintf(fPtr, "%c", Byte); // Byte 45
	
	// Print bmp_num_of_colors_in_palette
	longInt = bmp_num_of_colors_in_palette;
	Byte = longInt;
	fprintf(fPtr, "%c", Byte); // Byte 46
	Byte = longInt>>8;
	fprintf(fPtr, "%c", Byte); // Byte 47
	Byte = longInt>>16;
	fprintf(fPtr, "%c", Byte); // Byte 48
	Byte = longInt>>24;
	fprintf(fPtr, "%c", Byte); // Byte 49
	
	// Print bmp_num_of_important_colors
	longInt = bmp_num_of_important_colors;
	Byte = longInt;
	fprintf(fPtr, "%c", Byte); // Byte 50
	Byte = longInt>>8;
	fprintf(fPtr, "%c", Byte); // Byte 51
	Byte = longInt>>16;
	fprintf(fPtr, "%c", Byte); // Byte 52
	Byte = longInt>>24;
	fprintf(fPtr, "%c", Byte); // Byte 53
	
	// Print actual data
	uint32_t x,y;
	for(y = 1; y <= bmp_height; y++) {
		
		for(x = 0; x < bmp_width; x++) {
			
			fprintf(fPtr, "%c", B_m[bmp_height-y][x]);
			fprintf(fPtr, "%c", G_m[bmp_height-y][x]);
			fprintf(fPtr, "%c", R_m[bmp_height-y][x]);		
		}
		
		for(x = 0; x < (bmp_width%4); x++) {
			
			fprintf(fPtr, "%c", 0);	
		}
	}
	
	fclose(fPtr);
	return 0;
} // mat2bmp()