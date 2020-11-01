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
    printf("Type \"exit\" to quit my CShell.\n");
    printf("Type \"list\" to check the command list.\n");
	FONT_WHI
}

void showHelp()
{
    printf("                HELP\n");
    printf("Type the number before command to check the usage of it.(0: exit)\n");
    int flag;
    while (1) {
	  printf(">>");
	scanf("%d", &flag);
	switch (flag) {
	case 1:
	    help_ls();
	    break;
	case 2:
	    help_echo();
	    break;
	case 3:
	    help_cat();
	    break;
	case 4:
	    help_mkdir();
	    break;
	case 5:
	    help_rm();
	    break;
	case 6:
	    help_cd();
	    break;
	case 7:
	    help_pwd();
	    break;
	case 8:
	    help_wc();
	    break;
	case 9:
	    help_touch();
	    break;
	case 10:
	    help_clear();
	    break;
	case 0:
		goto end;
	default:
	    printf("Error input\n");
	}
    }
end:
	printf("Exit Help Successfully\n");
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
    printf("--------------------------\n");
	FONT_WHI
}
