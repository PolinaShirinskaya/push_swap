PUSH_SWAP				=	push_swap

CC						=	gcc
CFLAGS					=	-Wall -Werror -Wextra
LIBRARIES				=	-L./libft -lft
INCLUDES				=	-I./includes

LIBFT					=	./libft/libft.a
HEADER					=	./includes/push_swap.h

SOURCES_DIR				=	srcs/
SOURCES_LIST_PS			=	push_swap.c \
							parsing_input_data.c \
							validation_input_data.c \
							create_a.c \
							create_new_result.c \
							add_command.c \
							commands_1.c \
							commands_2.c \
							utils.c \
							utils_stack.c \
							private_sort.c \
							get_result.c \
							radix_sort.c \
							output_result.c \
							free.c
SOURCES_PS				=	$(addprefix $(SOURCES_DIR), $(SOURCES_LIST_PS))

OBJECTS_LIST_PS			=	${patsubst %.c, %.o, ${SOURCES_LIST_PS}}

all : ${PUSH_SWAP}

${PUSH_SWAP} : Makefile $(HEADER) $(LIBFT) $(OBJECTS_LIST_PS)
	@${CC} ${CFLAGS} -o $@ ${OBJECTS_LIST_PS} ${LIBRARIES} ${INCLUDES}
	@printf "'${PUSH_SWAP}' was compiled\n"

$(LIBFT) : ./libft/Makefile ./libft/libft.h ./libft/*.c
	@make -C ./libft
	@printf "libft was compiled\n"

%.o : $(addprefix $(SOURCES_DIR), %.c)
	$(CC) -c $(CFLAGS) $< -o $@ $(INCLUDES)

clean :
	@make clean -C ./libft
	@rm -rf $(OBJECTS_LIST_PS)
	@printf "command 'clean' was done\n"

fclean : clean
	@make fclean -C ./libft
	@rm -rf ${PUSH_SWAP}
	@printf "command 'fclean' was done\n"

re : fclean all
	@printf "command 're' was done\n"

.PHONY: all clean fclean re
