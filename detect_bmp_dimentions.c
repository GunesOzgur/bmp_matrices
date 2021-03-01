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

void detect_bmp_dimentions(char* bmpName)
{
	// Detects width and hight of a bitmap image
	
	// Arguments:
	// bmpName -> name of the BMP file
	
	FILE *fPtr;
	
	if( (fPtr = fopen(bmpName, "rb")) == NULL ) {

		MessageBox(0, bmpName, "Not opened!",
			MB_ICONEXCLAMATION | MB_OK | MB_SYSTEMMODAL);
		
		return;
	}
	
	uint8_t Byte;
	
	// Scan bmp_header
	fscanf(fPtr, "%c", &Byte); // Byte 0
	fscanf(fPtr, "%c", &Byte); // Byte 1
	
	// Scan bmp_total_size
	fscanf(fPtr, "%c", &Byte); // Byte 2
	fscanf(fPtr, "%c", &Byte); // Byte 3
	fscanf(fPtr, "%c", &Byte); // Byte 4
	fscanf(fPtr, "%c", &Byte); // Byte 5
	fscanf(fPtr, "%c", &Byte); // Byte 6
	fscanf(fPtr, "%c", &Byte); // Byte 7
	fscanf(fPtr, "%c", &Byte); // Byte 8
	fscanf(fPtr, "%c", &Byte); // Byte 9
	
	// Scan bmp_data_adress
	fscanf(fPtr, "%c", &Byte); // Byte 10
	fscanf(fPtr, "%c", &Byte); // Byte 11
	fscanf(fPtr, "%c", &Byte); // Byte 12
	fscanf(fPtr, "%c", &Byte); // Byte 13
	
	// Scan bmp_CoreHeader_size
	fscanf(fPtr, "%c", &Byte); // Byte 14
	fscanf(fPtr, "%c", &Byte); // Byte 15
	fscanf(fPtr, "%c", &Byte); // Byte 16
	fscanf(fPtr, "%c", &Byte); // Byte 17
	
	// Scan bmp_width
	fscanf(fPtr, "%c", &Byte); // Byte 18
	bmp_width = (uint32_t)Byte;
	fscanf(fPtr, "%c", &Byte); // Byte 19
	bmp_width += (uint32_t)(Byte*0x100);
	fscanf(fPtr, "%c", &Byte); // Byte 20
	bmp_width += (uint32_t)(Byte*0x10000);
	fscanf(fPtr, "%c", &Byte); // Byte 21
	bmp_width += (uint32_t)(Byte*0x1000000);
	
	// Scan bmp_height
	fscanf(fPtr, "%c", &Byte); // Byte 22
	bmp_height = (uint32_t)Byte;
	fscanf(fPtr, "%c", &Byte); // Byte 23
	bmp_height += (uint32_t)(Byte*0x100);
	fscanf(fPtr, "%c", &Byte); // Byte 24
	bmp_height += (uint32_t)(Byte*0x10000);
	fscanf(fPtr, "%c", &Byte); // Byte 25
	bmp_height += (uint32_t)(Byte*0x1000000);
	
	fclose(fPtr);
} // detect_bmp_dimentions