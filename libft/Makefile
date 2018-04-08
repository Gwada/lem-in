CC = gcc

NAME	= libft.a

HEADER = -I includes/

CFLAGS = -Wall -Wextra -Werror  $(HEADER)

SRC = mem/ft_memset.c \
		ft_bzero.c \
		mem/ft_memcpy.c \
		mem/ft_memccpy.c \
		mem/ft_memmove.c \
		mem/ft_memchr.c \
		mem/ft_memcmp.c \
		str/ft_strlen.c \
		str/ft_strdup.c \
		str/ft_strcpy.c \
		str/ft_strncpy.c \
		str/ft_strcat.c \
		str/ft_strncat.c \
		str/ft_strlcat.c \
		str/ft_strchr.c \
		str/ft_strrchr.c \
		str/ft_strstr.c \
		str/ft_strnstr.c \
		str/ft_strcmp.c \
		str/ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_isprint.c \
		mem/ft_memalloc.c \
		mem/ft_memdel.c \
		str/ft_strnew.c \
		str/ft_strdel.c \
		str/ft_strclr.c \
		str/ft_striter.c \
		str/ft_striteri.c \
		str/ft_strmap.c\
		str/ft_strmapi.c \
		str/ft_strequ.c \
		str/ft_strnequ.c \
		str/ft_strsub.c \
		str/ft_strjoin.c \
		str/ft_strtrim.c \
		str/ft_strsplit.c \
		ft_itoa.c \
		put/ft_putchar.c \
		put/ft_putstr.c \
		put/ft_putendl.c \
		put/ft_putnbr.c \
		put/ft_putchar_fd.c \
		put/ft_putstr_fd.c \
		put/ft_putendl_fd.c \
		put/ft_putnbr_fd.c \
		lst/ft_lstnew.c \
		lst/ft_lstdelone.c \
		lst/ft_lstdel.c \
		lst/ft_lstadd.c \
		lst/ft_lstiter.c \
		lst/ft_lstmap.c \
		ft_isupper.c \
		ft_islower.c \
		ft_countnumber.c \
		put/ft_putnbrendl.c \
		ft_countwords.c \
		ft_printstrsplit_tab.c \
		str/ft_strsplit_lst.c \
		put/ft_putlst.c \
		lst/ft_lstcount.c \
		file/ft_fileaddone.c \
		file/ft_filedelone.c \
		pile/ft_pileaddone.c \
		pile/ft_piledelone.c \
		str/ft_strsplit_file.c \
		str/ft_strsplit_pile.c \
		str/ft_str_is_printable.c \
		str/ft_str_is_uppercase.c \
		str/ft_str_is_numeric.c \
		str/ft_str_is_alpha.c \
		str/ft_strcapitalize.c \
		str/ft_strlowercase.c \
		str/ft_str_is_lowercase.c \
		str/ft_strupcase.c \
		ft_swap.c \
		str/ft_strchri.c \
		str/ft_strchri_up.c \
		ft_wstrlen.c \
		ft_wcharlen.c \
		get_next_line/get_next_line.c \
		ft_printf/attribuate.c \
		ft_printf/ft_printf.c \
		ft_printf/ft_dprintf.c \
		ft_printf/ft_sprintf.c \
		ft_printf/parsing.c \
		ft_printf/set_car.c \
		ft_printf/set_string.c \
		ft_printf/set_nbr.c \
		ft_printf/set_float.c \
		ft_printf/set_len.c \
		ft_printf/set_bin.c \
		ft_printf/set_colors.c \
		ft_printf/set_adress.c \
		ft_printf/ft_no_types.c \
		ft_printf/ft_filler.c \
		ft_printf/ft_buffering.c \

OBJ = $(addprefix sources/,$(SRC:.c=.o))

T = $(words $(SRC))
N = 0
C = $(words $N)$(eval N := x $N)
ECHO = "[`expr $C '*' 100 / $T`%]"

#Color
_GREY=\x1b[30m
_RED=\x1b[31m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_BLUE=\x1b[34m
_PURPLE=\x1b[35m
_CYAN=\x1b[36m
_WHITE=\x1b[37m
_END=\x1b[0m

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $?
	@ranlib $(NAME)
	@echo "$(_CYAN)$(NAME)$(_END)			: $(_GREEN)edited$(_END)"

%.o: %.c
	@printf "%-60b\r" "$(ECHO)"
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@rm -f libft.h.gch
#	@echo "$(_RED)clean libft$(_END) :	$(_GREEN)done$(_END)"

fclean:	clean
	@rm -f $(NAME)
#	@echo "$(_RED)fclean libft$(_END) :	$(_GREEN)done$(_END)"

re: fclean
	@make all

.PHONY: all re clean clean
