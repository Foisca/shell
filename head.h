#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <libgen.h>

#define SIZE 1024

void getCmd(char* buff, char* cmd[]);
void showShell(void);
void getInput(char buff[]);
void myLS(char *filename);
void myECHO(char text[]);
void myCAT(char *filename);
void myMKDIR(char *dirname);
void myRM(char *filename);
void myCD(char *path);
void myPWD();
void myWC(char *filename);

