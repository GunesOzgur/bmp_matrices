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

int bmp2mat(
	char* bmpName,
	uint8_t R_m[bmp_height][bmp_width],
	uint8_t G_m[bmp_height][bmp_width],
	uint8_t B_m[bmp_height][bmp_width])
{
	// Transfer the data from the BMP file into RGB matrices.
	
	// Arguments:
	// bmpName -> name for the BMP that will be read.
	// R_m -> RED Channel Matrix.
	// G_m -> GREEN Channel Matrix.
	// B_m -> BLUE Channel Matrix.
	
	// Recommended to detect bmp_height and bmp_width
	// before calling this function.
	
	FILE *fPtr;
	
	if( (fPtr = fopen(bmpName, "rb")) == NULL ) {

		MessageBox(0, bmpName, "Not opened!",
			MB_ICONEXCLAMATION | MB_OK | MB_SYSTEMMODAL);
		
		return -1;
	}
	
	uint8_t Byte;
	
	// Scan bmp_header
	fscanf(fPtr, "%c", &Byte); // Byte 0
	fscanf(fPtr, "%c", &Byte); // Byte 1
	
	// Scan bmp_total_size
	fscanf(fPtr, "%c", &Byte); // Byte 2
	bmp_total_size = (uint64_t)Byte;
	fscanf(fPtr, "%c", &Byte); // Byte 3
	bmp_total_size += (uint64_t)(Byte*0x100);
	fscanf(fPtr, "%c", &Byte); // Byte 4
	bmp_total_size += (uint64_t)(Byte*0x10000);
	fscanf(fPtr, "%c", &Byte); // Byte 5
	bmp_total_size += (uint64_t)(Byte*0x1000000);
	fscanf(fPtr, "%c", &Byte); // Byte 6
	bmp_total_size += (uint64_t)(Byte*0x100000000);
	fscanf(fPtr, "%c", &Byte); // Byte 7
	bmp_total_size += (uint64_t)(Byte*0x10000000000);
	fscanf(fPtr, "%c", &Byte); // Byte 8
	bmp_total_size += (uint64_t)(Byte*0x1000000000000);
	fscanf(fPtr, "%c", &Byte); // Byte 9
	bmp_total_size += (uint64_t)(Byte*0x100000000000000);
	
	// Scan bmp_data_adress
	fscanf(fPtr, "%c", &Byte); // Byte 10
	bmp_data_adress = (uint32_t)Byte;
	fscanf(fPtr, "%c", &Byte); // Byte 11
	bmp_data_adress += (uint32_t)(Byte*0x100);
	fscanf(fPtr, "%c", &Byte); // Byte 12
	bmp_data_adress += (uint32_t)(Byte*0x10000);
	fscanf(fPtr, "%c", &Byte); // Byte 13
	bmp_data_adress += (uint32_t)(Byte*0x1000000);
	
	// Scan bmp_CoreHeader_size
	fscanf(fPtr, "%c", &Byte); // Byte 14
	bmp_CoreHeader_size = (uint32_t)Byte;
	fscanf(fPtr, "%c", &Byte); // Byte 15
	bmp_CoreHeader_size += (uint32_t)(Byte*0x100);
	fscanf(fPtr, "%c", &Byte); // Byte 16
	bmp_CoreHeader_size += (uint32_t)(Byte*0x10000);
	fscanf(fPtr, "%c", &Byte); // Byte 17
	bmp_CoreHeader_size += (uint32_t)(Byte*0x1000000);
	
	// Scan bmp_width (assuming it detected previously)
	fscanf(fPtr, "%c", &Byte); // Byte 18
	fscanf(fPtr, "%c", &Byte); // Byte 19
	fscanf(fPtr, "%c", &Byte); // Byte 20
	fscanf(fPtr, "%c", &Byte); // Byte 21
	
	// Scan bmp_height (assuming it detected previously)
	fscanf(fPtr, "%c", &Byte); // Byte 22
	fscanf(fPtr, "%c", &Byte); // Byte 23
	fscanf(fPtr, "%c", &Byte); // Byte 24
	fscanf(fPtr, "%c", &Byte); // Byte 25
	
	// Scan bmp_color_planes
	fscanf(fPtr, "%c", &Byte); // Byte 26
	bmp_color_planes = (uint16_t)Byte;
	fscanf(fPtr, "%c", &Byte); // Byte 27
	bmp_color_planes += (uint16_t)(Byte*0x100);
	
	// Scan bmp_bit_per_pixel
	fscanf(fPtr, "%c", &Byte); // Byte 28
	bmp_bit_per_pixel = (uint16_t)Byte;
	fscanf(fPtr, "%c", &Byte); // Byte 29
	bmp_bit_per_pixel += (uint16_t)(Byte*0x100);
	
	// Scan bmp_compression_method
	fscanf(fPtr, "%c", &Byte); // Byte 30
	bmp_compression_method = (uint32_t)Byte;
	fscanf(fPtr, "%c", &Byte); // Byte 31
	bmp_compression_method += (uint32_t)(Byte*0x100);
	fscanf(fPtr, "%c", &Byte); // Byte 32
	bmp_compression_method += (uint32_t)(Byte*0x10000);
	fscanf(fPtr, "%c", &Byte); // Byte 33
	bmp_compression_method += (uint32_t)(Byte*0x1000000);
	
	// Scan bmp_data_size
	fscanf(fPtr, "%c", &Byte); // Byte 34
	bmp_data_size = (uint32_t)Byte;
	fscanf(fPtr, "%c", &Byte); // Byte 35
	bmp_data_size += (uint32_t)(Byte*0x100);
	fscanf(fPtr, "%c", &Byte); // Byte 36
	bmp_data_size += (uint32_t)(Byte*0x10000);
	fscanf(fPtr, "%c", &Byte); // Byte 37
	bmp_data_size += (uint32_t)(Byte*0x1000000);
	
	// Scan bmp_horizontal_resolution
	fscanf(fPtr, "%c", &Byte); // Byte 38
	bmp_horizontal_resolution = (uint32_t)Byte;
	fscanf(fPtr, "%c", &Byte); // Byte 39
	bmp_horizontal_resolution += (uint32_t)(Byte*0x100);
	fscanf(fPtr, "%c", &Byte); // Byte 40
	bmp_horizontal_resolution += (uint32_t)(Byte*0x10000);
	fscanf(fPtr, "%c", &Byte); // Byte 41
	bmp_horizontal_resolution += (uint32_t)(Byte*0x1000000);
	
	// Scan bmp_vertical_resolution
	fscanf(fPtr, "%c", &Byte); // Byte 42
	bmp_vertical_resolution = (uint32_t)Byte;
	fscanf(fPtr, "%c", &Byte); // Byte 43
	bmp_vertical_resolution += (uint32_t)(Byte*0x100);
	fscanf(fPtr, "%c", &Byte); // Byte 44
	bmp_vertical_resolution += (uint32_t)(Byte*0x10000);
	fscanf(fPtr, "%c", &Byte); // Byte 45
	bmp_vertical_resolution += (uint32_t)(Byte*0x1000000);
	
	// Scan bmp_num_of_colors_in_palette
	fscanf(fPtr, "%c", &Byte); // Byte 46
	bmp_num_of_colors_in_palette = (uint32_t)Byte;
	fscanf(fPtr, "%c", &Byte); // Byte 47
	bmp_num_of_colors_in_palette += (uint32_t)(Byte*0x100);
	fscanf(fPtr, "%c", &Byte); // Byte 48
	bmp_num_of_colors_in_palette += (uint32_t)(Byte*0x10000);
	fscanf(fPtr, "%c", &Byte); // Byte 49
	bmp_num_of_colors_in_palette += (uint32_t)(Byte*0x1000000);
	
	// Scan bmp_num_of_important_colors
	fscanf(fPtr, "%c", &Byte); // Byte 50
	bmp_num_of_important_colors = (uint32_t)Byte;
	fscanf(fPtr, "%c", &Byte); // Byte 51
	bmp_num_of_important_colors += (uint32_t)(Byte*0x100);
	fscanf(fPtr, "%c", &Byte); // Byte 52
	bmp_num_of_important_colors += (uint32_t)(Byte*0x10000);
	fscanf(fPtr, "%c", &Byte); // Byte 53
	bmp_num_of_important_colors += (uint32_t)(Byte*0x1000000);
	
	// Print actual data
	uint32_t x,y;
	for(y = 1; y <= bmp_height; y++) {
		
		for(x = 0; x < bmp_width; x++) {
			
			fscanf(fPtr, "%c", &B_m[bmp_height-y][x]);
			fscanf(fPtr, "%c", &G_m[bmp_height-y][x]);
			fscanf(fPtr, "%c", &R_m[bmp_height-y][x]);		
		}
		
		for(x = 0; x < (bmp_width%4); x++) {
			
			fscanf(fPtr, "%c", &Byte);	
		}
	}
	
	fclose(fPtr);
	return 0;
} // bmp2mat()