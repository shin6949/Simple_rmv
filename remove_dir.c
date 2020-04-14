#include <dirent.h>
#include <unistd.h>
#include <stdio.h>

int remove_dir(char* dirpath) {
	DIR* dp;

	if ((dp = opendir(dirpath)) == NULL)
	{
		perror("Open Error : ");
		return -1;
	}
	printf("디렉터리 %c를 삭제하였습니다.\n", dirpath);

	int status = rmdir(dirpath);

	closedir(dp);
	return status;
}
