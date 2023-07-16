
NAME			= so_long
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror 

FOLDER_HDR		= includes/

HEADER_SRC		= so_long.h

FOLDER			= sources/
FOLDER_COM		= utils_gnl/
PRINT_F			= printf/

SRCS			= 	initial_map.c\
					main.c\
					movement.c\
					path.c\
					so_long.c\
					verify.c\
					

SRCS_COM		= 	get_next_line.c\
					get_next_line_utils.c\

PRINT_F_SRC		= 	ft_printf.c\
					forma_my_char.c\
					forma_my_nbr.c\
					forma_my_putstr.c\
					ft_argputnbr_base.c\

SRC				= $(addprefix ${FOLDER}, ${SRCS})
SRC_COM			= $(addprefix ${FOLDER_COM}, ${SRCS_COM})
PRINT_ADD		= $(addprefix ${PRINT_F}, ${PRINT_F_SRC})

OBJS			= ${SRC:.c=.o}
OBJS_COM		= ${SRC_COM:.c=.o}
PRINT_F_OBJ		= ${PRINT_ADD:.c=.o}

OS				= $(shell uname -s)

ifeq ($(OS),Darwin)
LIB				= -lmlx -framework OpenGL -framework AppKit
endif
OBJ				= ${OBJS} ${OBJS_COM} ${PRINT_F_OBJ}
HEADER			= $(addprefix ${FOLDER_HDR}, ${HEADER_SRC})

ifdef DEBUG
CFLAGS			+= -fsanitize=address -g3
endif

%.o: %.c	${HEADER}
			@${CC} ${CFLAGS} -c -o $@ $<

${NAME}:	${OBJ}
			${COMPIL_MLX}
			@printf "$(GREEN)Creating ${NAME} executable\n$(RES)"
			@${CC} ${CFLAGS} ${OBJ} ${LIB} -o ${NAME}

all:		${NAME}

clean:
			@printf "$(RED)Destroying ${NAME} objs (*.o)\n$(RES)"
			@${RM} ${OBJS} ${OBJS_BNS} ${OBJS_COM} ${PRINT_F_OBJ}
			@${COMPIL_MLX} ${CLEAN}

fclean:		clean
			@printf "$(RED)Destroying ${NAME} executable\n$(RES)"
			@${RM} ${NAME}

re:			fclean all

bonus:
			@${MAKE} --no-print-directory BONUS=1

debug:		clean
			@printf "$(BLUE)Added Debug Flags !\n$(RES)"
			@${MAKE} -s --no-print-directory DEBUG=1
			@${MAKE} -s --no-print-directory clean
			@printf "$(BLUE)Next make wil recompile without debug flags :)\n$(RES)"

norm:
			norminette includes/ srcs/ srcs_com/ srcs_bonus/

.PHONY:		all clean fclean re bonus norm debug

RES			= \e[0m
RED			= \e[1;31m
GREEN		= \e[1;32m
BLUE		= \e[1;34m