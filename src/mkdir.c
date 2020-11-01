#include "mkdir.h"
void myMkdir(int argc, char* argv[])
{
    if (argc != 2) {
	printf("Usage:%s dirname", basename(argv[0]));
	return;
    }
    if (mkdir(argv[1], 0770) != 0)
	perror("mkdir"), exit(-1);
    printf("mkdir directory  success .\n");
    return;
}
