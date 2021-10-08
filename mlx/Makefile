#
#

NAME=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2
# added the following 4 lines to silence all the warnings created
%.o : %.c
	@cc -O2 -w -DSTRINGPUTX11   -c -o $@ $<
%.o : %.m
	@cc -O2 -w -DSTRINGPUTX11   -c -o $@ $<

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

all: $(NAME)

$(NAME):	$(OBJ)
	ar -r $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(NAME) $(OBJ) *~
	rm -f mlx_app

re: clean all
