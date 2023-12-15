#
# CSSE 132
# Rose-Hulman Institute of Technology
# Computer Science and Software Engineering
#
# Makefile - This is used to make the homework.
#



AS=arm-linux-gnueabihf-as 
CC=arm-linux-gnueabihf-gcc
LD=arm-linux-gnueabihf-ld

default: test test_asm

test_asm: test_asm.c unity/unity_asm.o asm.o
	${CC} -g -o test_asm test_asm.c asm.o unity/unity_asm.o 

test: test.c unity/unity.o problems.c
	gcc -g -Wl,-wrap,printf -fno-builtin-printf -o test test.c problems.c unity/unity.o

unity/unity_asm.o: unity/unity.c
	${CC} -c -o unity/unity_asm.o -Iunity unity/unity.c

unity/unity.o: unity/unity.c
	gcc -c -o unity/unity.o -Iunity unity/unity.c

problems.o: problems.c
	gcc -c -o problems.o problems.c

asm.o: problems.s
	${AS} problems.s -o asm.o 

run: test_asm
	qemu-arm -L /usr/arm-linux-gnueabihf ./test_asm

run-gdb: test_asm
	qemu-arm -L /usr/arm-linux-gnueabihf -g 1234 ./test_asm &
	gdb-multiarch --ex="set sysroot /usr/arm-linux-gnueabihf/" --ex="target remote localhost:1234" --ex="break main" --ex="continue" test_asm


clean:
	rm test test_asm *.o ./unity/*.o
