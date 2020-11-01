#include "pwd.h"

void myPwd()
{
    //pwd
    char buf[1024];
    char* cwd = getcwd(buf, sizeof(buf));
    if (NULL == cwd) {
	perror("Get cerrent working directory fail.\n");
	exit(-1);
    } else {
	puts(cwd);
    }
}

