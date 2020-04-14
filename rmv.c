#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <getopt.h>
#include <dirent.h>
#include <stdbool.h>
#include "status.h"
#include "remove_file.h"
#include "remove_dir.h"

static struct option long_options[] = {
	{"recursive", 0, NULL, 'r'},
	{NULL, 0, NULL, 0} 
};

static struct option_status status;

int main(int argc, char* argv[]) {
	int c;

	while (1) {
		int option_index = 0;

		c = getopt_long(argc, argv, "r:", long_options, &option_index);

		if (c == -1)
			break;

		switch (c) {
		case 0:
			break;

		case 'r':
			status.is_Directory = true;
			if (remove_dir(argv[2]) == -1) {
				perror("폴더 삭제 실패 - 폴더 안에 파일이 있거나 사용 중입니다.\n");
			}
			break;

		default:
			break;
		}
	}



	if (remove_file(argv[1]) == 0) { printf("삭제 성공\n"); }
	else if (remove_file(argv[1]) == -1) { perror("remove error"); }

	return 0;
}