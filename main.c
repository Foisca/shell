#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "func.h"
#include "ls.h"
#include "touch.h"

int main()
{
    printf("**** Welcome to CShell *****\n");
    while (1) {
	char buff[1024] = { 0 };
	char* cmd[20];
	showShell();
	getInput(buff);
	int nums = getCmd(buff, cmd);
	//printf("%d\n", nums);

	if ((strcmp(cmd[0], "ls")) == 0) {
	    myLS(nums, cmd);
	} else if ((strcmp(cmd[0], "echo") == 0)) {
	    myECHO(cmd[1]);
	} else if ((strcmp(cmd[0], "cat") == 0)) {
	    myCAT(cmd[1]);
	} else if (strcmp(cmd[0], "mkdir") == 0) {
	    myMKDIR(cmd[1]);
	} else if (strcmp(cmd[0], "rm") == 0) {
	    myRM(cmd[1]);
	} else if (strcmp(cmd[0], "cd") == 0) {
	    myCD(cmd[1]);
	} else if (strcmp(cmd[0], "pwd") == 0) {
	    myPWD();
	} else if (strcmp(cmd[0], "wc") == 0) {
	    myWC(cmd[1]);
	} else if (strcmp(cmd[0], "touch") == 0) {
	    myTouch(nums, cmd);
	} else if (strcmp(cmd[0], "exit") == 0) {
	    printf("Exit C Shell Successfully\n");
	    putchar('\n');
	    return 0;
	} else {
	    printf("Input Not Recognizeable\n");
	}
	if (NULL == cmd[0])
	    continue;
    }
}
