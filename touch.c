#include "touch.h"

//acess time and modify time
static int change_times;
// -c
static bool no_create;
// new a/m time
static struct timespec newtime[2];

static bool mytouch(const char* file)
{
    bool ok;
    int fd = -1;
    if (no_create != 1)
	fd = open(file, O_CREAT | O_WRONLY, MODE_RW_UGO);

    if (change_times != (CH_ATIME | CH_MTIME)) {
	if (change_times == CH_ATIME)
	    newtime[1].tv_nsec = UTIME_OMIT;
	else
	    newtime[0].tv_nsec = UTIME_OMIT;
    }
    ok = (utimensat(AT_FDCWD, file, newtime, 0) == 0);
    return ok;
}

void myTouch(int argc, char** argv)
{
    int c;
    bool ok = true;

    no_create = false;
    change_times = 0;

    while ((c = getopt(argc, argv, "acm")) != -1) {
	switch (c) {
	case 'a':
	    change_times |= CH_ATIME;
	    break;

	case 'c':
	    no_create = true;
	    break;

	case 'm':
	    change_times |= CH_MTIME;
	    break;

	default:
	    printf("fault option!");
	}
    }

    if (change_times == 0)
	change_times = CH_ATIME | CH_MTIME;

    newtime[0].tv_nsec = UTIME_NOW;
    newtime[1].tv_nsec = UTIME_NOW;

    if (argc == optind)
	printf("missing file operand\n");

    for (; optind < argc; ++optind)
	ok &= mytouch(argv[optind]);

}
