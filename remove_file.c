#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int remove_file(char* filepath[]) {
	int fd = 0;
	fd = open(filepath, O_WRONLY);
	if (fd == -1) {
		perror("remove_file error open");
		return 1;
	}

	int status = remove(filepath);

	close(fd);
	return status;
}
