/* bmp_matrices.h
 *
 * Header file of "bmp_matrices" project.
 *
 * "bmp_matrices" enables to make modifications
 * on bitmap images by means of matrices.
 *
 * Last modified on March 01, 2021
 *
 * by Freeman Sun
*/

#include <stdint.h>
#include <stdio.h>
#include <windows.h>

// Global Variables for BMP Chunks
uint16_t bmp_header; // Bytes 0-1
uint64_t bmp_total_size; // Bytes 2-9
uint32_t bmp_data_adress; // Bytes 10-13
uint32_t bmp_CoreHeader_size; // Bytes 14-17
uint32_t bmp_width; // Bytes 18-21
uint32_t bmp_height; // Bytes 22-25
uint16_t bmp_color_planes; // Bytes 26-27
uint16_t bmp_bit_per_pixel; // Bytes 28-29
uint32_t bmp_compression_method; // Bytes 30-33
uint32_t bmp_data_size; // Bytes 34-37
uint32_t bmp_horizontal_resolution; // Bytes 38-41
uint32_t bmp_vertical_resolution; // Bytes 42-45
uint32_t bmp_num_of_colors_in_palette; // Bytes 46-49
uint32_t bmp_num_of_important_colors; // Bytes 50-54

// Function prototypes
int mat2bmp(
	uint8_t R_m[bmp_height][bmp_width],
	uint8_t G_m[bmp_height][bmp_width],
	uint8_t B_m[bmp_height][bmp_width],
	char* bmpName);
int bmp2mat(
	char* bmpName,
	uint8_t R_m[bmp_height][bmp_width],
	uint8_t G_m[bmp_height][bmp_width],
	uint8_t B_m[bmp_height][bmp_width]);
void detect_bmp_dimentions(char* bmpName);
