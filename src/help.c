#include "help.h"
void help_ls()
{
    printf("ls - list directory contents\n");
    printf("List information about the files and directories under the typed directory (current directory by default)\n");
}

void help_echo()
{
    printf("echo - display a line of text\n");
    printf("-n\tdo not output the trailing newline\n");
}

void help_cat()
{
    printf("cat - concatenate files and print on the standard output\n");
}

void help_mkdir()
{
    printf("mkdir - make directories\n");
}

void help_rm()
{
    printf("remove files or directories\n");
    printf("-r, -R, --recursive\n");
    printf("\tremove directories and their contents recursively\n");
}

void help_cd()
{
    printf("cd - change the working directory\n");
}

void help_pwd()
{
    printf("pwd - print name of current/working directory\n");
}

void help_wc()
{
    printf("wc - print newline, word, and byte conunts for each file\n");
}

void help_touch()
{
    printf("touch - change file timestamps, or create a new file\n");
}

void help_clear()
{
    printf("clear - clear the terminal screen\n");
}
