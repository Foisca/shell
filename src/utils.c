#include "utils.h"
#include "help.c"

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
    uid_t uid;
    char* ret;
    struct passwd* user;
    char hostname[100];
    char cwd[120];
    uid = getuid();
    user = getpwuid(uid);
    FONT_GRE
    printf("[%s@", user->pw_name); // 打印用户名
    FONT_CYA
    gethostname(hostname, 100);
    printf("%s:", hostname); // 打印主机名
    getcwd(cwd, 120);
    if (strcmp(cwd, user->pw_dir) == 0) {
	FONT_BLU
	printf("~"); // 家目录特殊处理

    } else {
	ret = strrchr(cwd, '/'); // 获取路径的最后一个目录
	FONT_GRE
	if (ret[1] == '\0') {
	    printf("/]"); // 根目录

	} else {
	    printf("%s]", ret + 1);
	}
    }
    if (0 == uid) {
	FONT_PUR
	printf("# "); // 超级用户
    } else {
	printf("$ "); // 普通用户
    }
    FONT_WHI
    fflush(stdout); // 刷新终端提示符
}

int getCmd(char* buff, char* cmd[])
{
    int idx = 0;
    char* ret;
    if (buff == NULL) {
	cmd = NULL;
	return 0;
    }
    ret = strtok(buff, " \t\n"); // 分割命令
    while (1) {
	cmd[idx++] = ret;
	if (NULL == ret) // 分割命令结束
	    return idx - 1;
	ret = strtok(NULL, " \t\n");
    }
    return idx - 1;
}

void showHello()
{
    FONT_BLU
    printf("         Welcome to CShell\n");
    printf("Type \"help\" to see detail operation of my CSehll\n");
	printf("eg.:help ls\n");
    printf("Type \"exit\" to quit my CShell.\n");
    printf("Type \"list\" to check the available command list.\n");
    FONT_WHI
}

void showHelp(char cmd[])
{
    if (strcmp(cmd, "ls") == 0) {
	help_ls();
    } else if ((strcmp(cmd, "echo") == 0)) {
	help_echo();
    } else if ((strcmp(cmd, "cat") == 0)) {
	help_cat();
    } else if (strcmp(cmd, "mkdir") == 0) {
	help_mkdir();
    } else if (strcmp(cmd, "rm") == 0) {
	help_rm();
    } else if (strcmp(cmd, "cd") == 0) {
	help_cd();
    } else if (strcmp(cmd, "pwd") == 0) {
	help_pwd();
    } else if (strcmp(cmd, "wc") == 0) {
	help_wc();
    } else if (strcmp(cmd, "touch") == 0) {
	help_touch();
    } else if (strcmp(cmd, "clear") == 0) {
	help_clear();
    } else if (strcmp(cmd, "list") == 0) {
	showComamndList();
    } else if (strcmp(cmd, "exit") == 0) {
	printf("Exit Help Successfully\n");
	putchar('\n');
    } else {
	printf("Input Not Recognizeable\n");
    }
}

void showComamndList()
{
    FONT_BLU
    printf("-------Commandlist--------\n");
    printf("|1.ls                    |\n");
    printf("|2.echo                  |\n");
    printf("|3.cat                   |\n");
    printf("|4.mkdir                 |\n");
    printf("|5.rm                    |\n");
    printf("|6.cd                    |\n");
    printf("|7.pwd                   |\n");
    printf("|8.wc                    |\n");
    printf("|9.touch                 |\n");
    printf("|10.clear                |\n");
    printf("|11.help                 |\n");
    printf("--------------------------\n");
    FONT_WHI
}
