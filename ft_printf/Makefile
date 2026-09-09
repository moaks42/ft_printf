NAME := libftprintf.a

CC := cc
CFLAGS := -Wall -Wextra -Werror
AR := ar -rc
RM := rm -f

INC := includes/ft_printf.h

SRC :=	ft_printf.c \
		ft_helper.c \
		ft_unsigned.c \

OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(res) $(NAME) $(OBJ)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re