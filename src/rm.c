
#include "rm.h"
void myRm(char* filename)
{
    //rm
    if (access(filename, 0) == -1) {
	return;
    }
    remove(filename);
}
