#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	struct utsname sysinfo;
	/*
	struct utsname {
		char sysname[];    // Operating system name (e.g., "Linux")
		char nodename[];   // Name within communications network
		char release[];    // Operating system release
		char version[];    // Operating system version 
		char machine[];    // Hardware type identifier 
	};
	*/

	if (uname(&sysinfo) == -1) {
		perror("uname");
		exit(1);
	}

	printf("OS: %s\n", sysinfo.sysname);
	printf("host: %s\n", sysinfo.nodename);
	printf("OS release: %s\n", sysinfo.release);
	printf("OS version: %s\n", sysinfo.version);
	printf("hardware: %s\n", sysinfo.machine);

	return 0;
}
