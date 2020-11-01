#include "head.h"
#include <stdlib.h>
int main()
{
    showHello();
    while (1) {
	char buff[1024] = { 0 };
	char** cmd;
	*cmd = (char*)malloc(sizeof(char) * 20);
	showShell();
	getInput(buff);
	int nums = getCmd(buff, cmd);

	if ((strcmp(cmd[0], "ls")) == 0) {
	    myLs(nums, cmd);
	} else if ((strcmp(cmd[0], "echo") == 0)) {
	    myEcho(nums, cmd);
	} else if ((strcmp(cmd[0], "cat") == 0)) {
	    myCat(nums, cmd);
	} else if (strcmp(cmd[0], "mkdir") == 0) {
	    myMkdir(nums, cmd);
	} else if (strcmp(cmd[0], "rm") == 0) {
	    myRm(cmd[1]);
	} else if (strcmp(cmd[0], "cd") == 0) {
	    myCd(cmd[1]);
	} else if (strcmp(cmd[0], "pwd") == 0) {
	    myPwd();
	} else if (strcmp(cmd[0], "wc") == 0) {
	    myWc(cmd[1]);
	} else if (strcmp(cmd[0], "touch") == 0) {
	    myTouch(nums, cmd);
	} else if (strcmp(cmd[0], "clear") == 0) {
	    myClear();
	} else if (strcmp(cmd[0], "help") == 0) {
	    showHelp();
	    cmd[0] = NULL;
	} else if (strcmp(cmd[0], "list") == 0) {
	    showComamndList();
	} else if (strcmp(cmd[0], "exit") == 0) {
	    printf("Exit CShell Successfully\n");
	    putchar('\n');
	    return 0;
	} else {
	    printf("Input Not Recognizeable\n");
	}
	free(*cmd);
	printf("do1\n");
    }
}
