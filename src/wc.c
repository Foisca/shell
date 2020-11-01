#include "wc.h"

void myWc(char* filename)
{
    //wc
    FILE* fp;
    int num = 0;
    if ((fp = fopen(filename, "r")) == NULL) {
	printf("Open file error\n");
	return;
    }
    while (!feof(fp)) {
	fgetc(fp);
	num++;
    }
    num--;
    printf("%s has %d characters\n", filename, num);
    fclose(fp);
    return;
}
