#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <libgen.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "func.h"

void getInput(char buff[])
{
    char ch;
    int idx = 0; // 光标索引
    buff[0] = '\0';
    while (1) {
	ch = getchar();
	if (ch == '\n')
	    return;
	buff[idx] = ch;
	idx++;
    }
}

void showShell(void)
{
    /* 终端提示符组成：[用户名+@+主机名+当前目录]+用户提示符 */

    uid_t uid;
    char* ret;
    struct passwd* user;
    char hostname[100];
    char cwd[120];

    /* 获取用户id */
    uid = getuid();

    /* 根据uid获取用户的passwd结构体 */
    user = getpwuid(uid);
    printf("[%s@", user->pw_name); // 打印用户名

    /* 获取主机名 */
    gethostname(hostname, 100);
    printf("%s:", hostname); // 打印主机名

    /* 获取当前工作目录 */
    getcwd(cwd, 120);
    if (strcmp(cwd, user->pw_dir) == 0) {
	printf("~"); // 家目录特殊处理

    } else {
	ret = strrchr(cwd, '/'); // 获取路径的最后一个目录
	if (ret[1] == '\0') {
	    printf("/]"); // 根目录

	} else {
	    printf("%s]", ret + 1);
	}
    }

    /* 打印用户提示符 */
    if (0 == uid) {
	printf("# "); // 超级用户

    } else {
	printf("$ "); // 普通用户
    }

    fflush(stdout); // 刷新终端提示符
}

int getCmd(char* buff, char* cmd[])
{
    int idx = 0;
    char* ret;

    ret = strtok(buff, " \t\n"); // 分割命令
    while (1) {
	cmd[idx++] = ret;
	if (NULL == ret) // 分割命令结束
	    return idx - 1;
	ret = strtok(NULL, " \t\n");
    }
    return idx - 1;
}

void myECHO(char text[])
{
    //echo
    if (text == NULL) {
	return;
    }
    puts(text);
}

void myCAT(char* filename)
{
    //cat
    FILE* fp;
    char buf[1024];
    fp = fopen(filename, "r");
    if (fp == NULL) {
	printf("Open file error\n");
	return;
    }
    while (fgets(buf, sizeof(buf), fp) != NULL) {
	int len = strlen(buf);
	buf[len - 1] = '\0';
	puts(buf);
    }
    fclose(fp);
}

void myMKDIR(char* dirname)
{
    //mkdir
    // 文件夹不存在则创建文件夹
    if (access(dirname, 0) == -1) {
	mkdir(dirname, S_IRWXU);
    }
}

void myRM(char* filename)
{
    //rm
    if (access(filename, 0) == -1) {
	return;
    }
    remove(filename);
}

void myCD(char* path)
{
    //cd
    chdir(path);
}

void myPWD()
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

void myWC(char* filename)
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


