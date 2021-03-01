:: Last modified on March 01, 2021
:: by Freeman Sun
::
:: Compile the modules of "bmp_matrices"
gcc -c main.c
gcc -c detect_bmp_dimentions.c
gcc -c bmp2mat.c
gcc -c mat2bmp.c
gcc -c init_bmp.c
::
:: Link them into "bmp_matrices.exe"
gcc main.o detect_bmp_dimentions.o bmp2mat.o mat2bmp.o init_bmp.c -o bmp_matrices.exe