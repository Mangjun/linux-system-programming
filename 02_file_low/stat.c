#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#ifdef MANUAL 
struct stat {
	dev_t      st_dev;      /* ID of device containing file */
	ino_t      st_ino;      /* Inode number */
	mode_t     st_mode;     /* File type and mode */
	nlink_t    st_nlink;    /* Number of hard links */
	uid_t      st_uid;      /* User ID of owner */
	gid_t      st_gid;      /* Group ID of owner */
	dev_t      st_rdev;     /* Device ID (if special file) */
	off_t      st_size;     /* Total size, in bytes */
	blksize_t  st_blksize;  /* Block size for filesystem I/O */
	blkcnt_t   st_blocks;   /* Number of 512 B blocks allocated */

	struct timespec  st_atim;  /* Time of last access */
	struct timespec  st_mtim;  /* Time of last modification */
	struct timespec  st_ctim;  /* Time of last status change */
};

S_ISREG(m)  is it a regular file?

S_ISDIR(m)  directory?

S_ISCHR(m)  character device?

S_ISBLK(m)  block device?

S_ISFIFO(m) FIFO (named pipe)?

S_ISLNK(m)  symbolic link?  (Not in POSIX.1-1996.)

S_ISSOCK(m) socket?  (Not in POSIX.1-1996.)
#endif

int main(int argc, char **argv)
{
	if (argc != 2) {
		printf("Usage: %s filename\n", argv[0]);
		return -1;
	}

	struct stat statbuf;

	if (stat(argv[1], &statbuf)) {
		perror("stat");
		return -1;
	}

	printf("filename: %s\n", argv[1]);
	printf("size: %ld\n", statbuf.st_size);

	if (S_ISDIR(statbuf.st_mode)) {
		printf("directory!\n");
	}
	else if (S_ISREG(statbuf.st_mode)) {
		printf("regular file!\n");
	}
	else {
		printf("???\n");
	}

	return 0;
}
