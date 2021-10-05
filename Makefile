
gcc -Imlx -c so_long.c -o so_long.o

gcc -Lmlx -lmlx -framework OpenGL so_long.o -framework AppKit -o so_long

./so_long
