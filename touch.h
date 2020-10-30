#include <fcntl.h>
#include <getopt.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define CH_ATIME 1
#define CH_MTIME 2

#define MODE_RW_UGO (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)
void myTouch(int argc, char** argv);
