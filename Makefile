all:
	gcc -Wall -Wextra -O3  -fwhole-program -flto=auto -pipe -march=native -mtune=native -o main ./*.c ./*/*.c ./*/*.h -lm

.PHONY: all
