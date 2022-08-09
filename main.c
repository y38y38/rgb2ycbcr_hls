#include  <stdio.h>
#include  <stdlib.h>
#include <stdint.h>

#include "rgb2ycbcr.h"


int conv_file(FILE *input, FILE *output)
{

	uint8_t *inbuf = (uint8_t*)malloc(FRAME_HORIZONTAL*FRAME_VERTICAL*3);
	if (inbuf == NULL) {
		printf("%s %d\n", __func__, __LINE__);
		return -1;
	}
	double *outbuf = (double*)malloc(FRAME_HORIZONTAL*FRAME_VERTICAL*3*sizeof(double));
	if (outbuf == NULL) {
		printf("%s %d\n", __func__, __LINE__);
		return  -1;
	}
	size_t readsize = fread(inbuf, 1, FRAME_HORIZONTAL*FRAME_VERTICAL*3, input);
	if (readsize != FRAME_HORIZONTAL*FRAME_VERTICAL*3) {
		printf("%s %d %d\n", __func__, __LINE__, (int)readsize);
		return  -1;
	}

	rgb2ycbcr(inbuf, outbuf);
//	printf("%d\n", sizeof(double));
	size_t writesize = fwrite(outbuf, 1, FRAME_HORIZONTAL*FRAME_VERTICAL*3*sizeof(double), output);
	if (writesize != FRAME_HORIZONTAL*FRAME_VERTICAL*3*sizeof(double)) {
        printf("fwrite err %s %d %d\n",__func__, __LINE__, (int)writesize);
		return -1;
	}

	return 0;
}


//parameter1 input file name
//parameter2  output file name

int main(int argc, char** argv[])
{
	if (argc != 3) {
		printf("cmm12_16 input_filename output_filename\n");
		return -1;
	}
	FILE *input = fopen((const char*)argv[1], "r");
	if (input == NULL) {
		printf("can't open file\n");
		return -1;
	}

	FILE *output = fopen((const char*)argv[2], "w");
	if (output == NULL) {
		printf("can't open file\n");
		return -1;
	}

	int ret = conv_file(input, output);
	if (ret < 0) {
		printf("ng\n");
		return -1;
	}

	fclose(input);
	fclose(output);
	return 0;
}

