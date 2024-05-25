LIBFT = ./libft
PS_PATH = ./srcs/push_swap
CHECKER_PATH = ./srcs/checker
SRCS = ${addprefix ${PS_PATH}/, push_swap_utils.c \
	push_swap_utils2.c \
	push_swap_utils3.c \
	main.c \
	stack_init.c \
	index_utils1.c \
	index_utils2.c \
	push_swap.c \
	swap.c \
	push.c \
	rotate.c \
	reverse.c \
	small_sort.c \
	big_sort.c}
SRCS_B = ${addprefix ${CHECKER_PATH}/,checker.c} ${addprefix ${PS_PATH}/,push_swap_utils.c \
	push_swap_utils2.c \
	push_swap_utils3.c \
	stack_init.c \
	swap.c \
	push.c \
	rotate.c \
	reverse.c \
	index_utils1.c}
OBJS = ${SRCS:.c=.o}
OBJS_B = ${SRCS_B:.c=.o}
NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
INCLUDE = ./includes

RESET = \033[0m
GRAS = \033[1m
ITALIQUE = \033[3m
SOULIGN = \033[4m
UP = \033[A
BLINK = \033[6m


ORANGE = \033[38;5;216m
DARKBLUE = \033[38;5;21m
RED = \033[38;5;130m
GREEN_FLUO = \033[38;5;85m
MAUVE = \033[35m

FICH_COUNT = 0
NBR_TOT_FICHIER = 14
NBR_COMPILER = ${shell expr 100 \* ${FICH_COUNT} / ${NBR_TOT_FICHIER}}
BAR =  ${shell expr 23 \* ${FICH_COUNT} / ${NBR_TOT_FICHIER}}


LIGHT_BLUE = \033[38;5;87m
DARK_BLUE = \033[0;34m
YELLOW = \033[1;33m
RESET = \033[0m

BLACK = \033[30m
RED = \033[31m
GREEN = \033[32m
GREEN_FLUO = \033[38;5;85m
YELLOW = \033[33m
BLUE = \033[34m
PURPLE = \033[38;5;63m
MAGENTA = \033[38;2;255;0;255m
CYAN = \033[0;36m

all : ${NAME}

bonus : ${BONUS}

%.o: %.c
	@${eval FICH_COUNT = ${shell expr ${FICH_COUNT} + 1}}
	@${CC} ${CFLAGS} -I ${INCLUDE} -c $< -o $@
	@echo ""
	@echo " ${GRAS}${MAUVE}-> COMPILATION EN COURS : ${RESET}${GRAS}${PURPLE}${NAME}${RESET}"
	@printf " ${MAUVE}${GRAS}[${PURPLE}%-23.${BAR}s${MAUVE}] [%d/%d (%d%%)]${RESET}" "#######################" ${FICH_COUNT} ${NBR_TOT_FICHIER} ${NBR_COMPILER}
	@echo "${UP}${UP}${UP}"


${NAME} : ${OBJS}
	@${MAKE} --silent -C ${LIBFT}
	@${CC} ${CFLAGS} ${OBJS} ${LIBFT}/libft.a -o ${NAME}
	@echo "\n\n\n  ${GRAS}${MAUVE}${NAME}${RESET}${GRAS}${MAUVE} EST COMPILÉ 🎉${RESET}\n"

${BONUS} : ${OBJS_B}
	@${MAKE} --silent -C ${LIBFT}
	@${CC} ${CFLAGS} ${OBJS_B} ${LIBFT}/libft.a -o ${BONUS}
	@printf "${GRAS}${YELLOW}  BONUS COMPILÉ ✅${RESET}\n"


clean:
	@${MAKE} clean --silent -C ${LIBFT}
	@${RM} ${OBJS} ${OBJS_B}
	@echo "\n${CYAN}${GRAS}\tNETTOYAGE 🛁${RESET}"
	@echo "${CYAN}${ITALIQUE} -les fichiers objets sont supprimés${RESET}"

fclean: clean
	@${MAKE} fclean --silent -C ${LIBFT}
	@${RM} ${NAME} ${BONUS}
	@echo "${CYAN}${ITALIQUE} -libft.a est supprimé${RESET}"
	@echo "${CYAN}${ITALIQUE} -${NAME} est supprimé${RESET}"

re: fclean all



.PHONY: all clean fclean re
