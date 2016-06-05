#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

all: $(NOM)

$(NOM):	$(OBJ)
	@ar -r $(NOM) $(OBJ)
	@ranlib $(NOM)
	@echo "\n---------------------------------------------------------"
	@echo "|\033[32;1m\t\t$(NOM) has been created !\t\t\033[0m|"
	@echo "---------------------------------------------------------\n"

clean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app
	@echo "\n-------------------------------------------------"
	@echo "|\t\033[31mall $(NOM) files.o are deleted\033[0m\t\t|"
	@echo "-------------------------------------------------\n"
	@echo "\n-----------------------------------------"
	@echo "|\t\033[31m$(NOM) is deleted\033[0m\t\t|"
	@echo "-----------------------------------------\n"

re: clean all
