#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
//#include "square.h"
#include <string.h>

#pragma pack(1)
typedef struct BITMAPFILEHEADER {
	short type;
	int size;
	int zero;
	int start;
} BITMAPFILEHEADER;
typedef struct info {
	int bcSize;
	int width;
	int height;
	short a;
	short bitSize;
	int biCompressions;
	int biSizeImage;
	int x;
	int y;
	int sizeTable;
	int countTableCol;
	int one;
	int two;
} info;


int mod(int a, int mod) {
	return (a % mod + mod) % mod;
}

int main(int argc, char **argv) {
	FILE *myFile = fopen(argv[1], "rb");
	//FILE *myFile = fopen("one.bmp", "rb");

	fseek(myFile, 0, SEEK_SET);
	BITMAPFILEHEADER head;

	info inf;
	fread(&head, 1, sizeof(BITMAPFILEHEADER), myFile);
	fread(&inf, 1, sizeof(info), myFile);
	char *bitMap = malloc(inf.biSizeImage);
	int aa = fread(bitMap, 1, inf.biSizeImage, myFile);

	char *oldGeneration = malloc(inf.biSizeImage * 8);
	for (int i = 0; i < inf.height; ++i) {//

		for (int j = 0; j < inf.width; j += 8) {
			for (int k = 0; k < 8; ++k) {
				oldGeneration[i * inf.width + j + k] =
					((bitMap[((i * inf.biSizeImage / inf.height + j / 8))] >> (7 - k))) & 1;

			}
		}

	}
	int n = 0;
	int k = 1;
	int infinity = 1;
	if (argc >= 3) {//
		if (argv[2][0] == 'n') {
			n = atoi(&argv[2][2]);
			infinity = 0;
		}
		else if ((argc > 3 && argv[3][0] == 'n')) {
			n = atoi(&argv[3][2]);
			infinity = 0;
		}
		if (argv[2][0] == 'k') {
			k = atoi(&argv[2][2]);
		}
		else if ((argc > 3 && argv[3][0] == 'k')) {
			k = atoi(&argv[3][2]);
			infinity = 0;
		}

	}
	int len = n;
	while (infinity || n--) {
		//printf("%d\n", n);
		char *newGeneration = malloc(inf.height * inf.width);

		for (int i = 0; i < inf.height; ++i) {
			for (int j = 0; j < inf.width; ++j) {
				int count = 0;
				for (int k = -1; k < 2; ++k) {
					for (int l = -1; l < 2; ++l) {
						if (oldGeneration[mod(i + k, inf.height) * inf.width + mod(j + l, inf.width)] == 0) {
							if (k == 0 && l == 0)
								count--;
							count++;
						}
					}
				}
				if (count == 3 || (oldGeneration[i * inf.width + j] == 0 && count == 2)) {
					newGeneration[i * inf.width + j] = 0;
				}
				else {
					newGeneration[i * inf.width + j] = 1;
				}
			}
		}
		int col = 0;
		for (int i = 0; i < inf.height; ++i) {//
			for (int j = 0; j < inf.biSizeImage / inf.height; ++j) {
				for (int k = 0; k < 8; ++k) {
					if (j * 8 + k < inf.width)
						bitMap[i * inf.biSizeImage / inf.height + j] =
						(bitMap[i * inf.biSizeImage / inf.height + j] << 1) |
						(newGeneration[i * inf.width + j * 8 + k]);
					else
						bitMap[i * inf.biSizeImage / inf.height + j] =
						(bitMap[i * inf.biSizeImage / inf.height + j] << 1);

				}
			}
		}
		char numb[33];
		for (int m = 0; m < 33; ++m) {
			numb[m] = 0;
		}
		//printf("%d ", (len - n) % k);
		if ((len - n) % k == 0) {
			FILE *out = fopen(strcat(itoa(n, numb, 10), ".bmp"), "wb");
			fwrite(&head, 1, sizeof(BITMAPFILEHEADER), out);
			fwrite(&inf, 1, sizeof(info), out);
			fwrite(bitMap, sizeof(char), inf.biSizeImage, out);
			fclose(out);
		}
		//printf("%d", aaa);
		free(oldGeneration);
		oldGeneration = newGeneration;
	}
	free(oldGeneration);
	free(bitMap);
	return 0;
}
