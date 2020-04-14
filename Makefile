remove_file.o: remove_file.c remove_file.h
	gcc -o remove_file.o remove_file.c

remove_dir.o: remove_dir.c remove_dir.h
	gcc -o remove_dir.o remove_dir.c

rmv.o: remove_file.h remove_file.c remove_dir.h remove_dir.c status.h
	gcc -o rmv.o rmv.c

rmv.out: rmv.o remove_file.o remove_dir.o status.h
	gcc -o rmv.out remove_file.o remove_dir.o
