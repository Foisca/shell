#include "func.cc"

int main()
{
    while (1) {
	char buff[SIZE] = { 0 };
	char* cmd[20];
	showShell();
	getInput(buff);
	//	puts(buff);
	getCmd(buff, cmd);
	//puts(cmd[0]);
	//puts(cmd[1]);
	/*
	for (int i = 0; i < 20; i++) {
	    if (strcmp(cmd[i], ""))
		break;
	    else
		puts(cmd[0]);
	}
*/
	if (strcmp(cmd[0], "ls") == 0) {
	    if ((strcmp(cmd[0], "ls")) == 0) {
		myLS(cmd[1]);
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
}
