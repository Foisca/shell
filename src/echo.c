#include "echo.h"


void myEcho(int argv, char* argc[])
{
    int i;
    int j;
    int len;	 //接收main函数后每个参数的长度
    char* p;	 //用来指向char数组中某个下标的地址
    char a[len]; //定义一个len长度的char数组
    if (strcmp(argc[1], "-n") == 0) {
	for (i = 2; i < argv; i++) {
	    printf("%s ", argc[i]);
	    if (i == argv - 2) {
		printf("%s", argc[argv - 1]);
		break;
	    }
	}
	//实现echo -e功能
    } else if (strcmp(argc[1], "-e") == 0) {
	for (i = 0; i < len; i++) {
	    a[i] = argc[argv - 1][i];
	}
	for (j = 2; j < argv; j++) {
	    len = strlen(argc[j]);
	    for (i = 0; i < len; i++) {
		p = &a[i];
		if (a[i] == '\\') {
		    if (a[i + 1] == 'n') {
			a[i] = '\n';
			i++;
		    } else if (a[i + 1] == 'a') {
			a[i] = '\a';
			i++;
		    } else if (a[i + 1] == 'b') {
			a[i] = '\b';
			i++;
		    } else if (a[i + 1] == 'f') {
			a[i] = '\f';
			i++;
		    } else if (a[i + 1] == 'r') {
			a[i] = '\r';
			i++;
		    } else if (a[i + 1] == 't') {
			a[i] = '\t';
			i++;
		    } else if (a[i + 1] == '\\') {
			a[i] = '\\';
			i++;
		    }
		}
		printf("%c", *p);
	    }
	    printf(" ");
	}
	printf("\n");
    } else { //实现echo 功能
	for (i = 1; i < argv; i++) {
	    printf("%s ", argc[i]);
	    //if (i == argv - 2) {
		//printf("%s\n", argc[argv - 1]);
		//break;
	    //}
	}
	printf("\n");
    }
}
