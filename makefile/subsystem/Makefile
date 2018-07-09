obj_by_test := main.o
subsystem:$(obj_by_test)
	gcc -o subsystem $(obj_by_test)
	@ echo "sub system link ok!"
main.o: main.c main.h
	gcc -c main.c
	@ echo "sub system complie ok!"
