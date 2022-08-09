#include <stdint.h>

#include "rgb2ycbcr.h"

void rgb2ycbcr(uint8_t *rgb, double *ycbcr){
	for (int i=0;i< FRAME_HORIZONTAL*FRAME_VERTICAL;i++) {
		//y
		ycbcr[(i*3)] = 0.2126 * rgb[(i*3) ] + 0.7152 * rgb[(i*3)+1] + 0.0722 * rgb[(i*3)+2];

		//cb
		ycbcr[(i*3)+1] = 0.114572 * rgb[(i*3) ] - 0.385428 * rgb[(i*3)+1] + 0.5 * rgb[(i*3)+2];

		//cb
		ycbcr[(i*3)+1] = 0.5 * rgb[(i*3) ] - 0.454153 * rgb[(i*3)+1] + 0.045847 * rgb[(i*3)+2];
		
	}
	return;
}

