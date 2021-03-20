SRCS		=	ft_write.s ft_strcmp.s ft_strcpy.s ft_strlen.s 
OBJS		=	$(SRCS:.s=.o)
FLAGS 		=	-Wall -Werror -Wextra
NAME		=	libasm.a
TEST		=	test

%.o:			%.s
				nasm -f macho64 $<

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				rm -rf $(OBJS)

fclean:			clean
				rm -rf $(NAME) $(TEST)

re:				fclean $(NAME)

test:			$(NAME)
				gcc $(FLAGS) -L. -lasm -o $(TEST) main.c
				./$(TEST)

.PHONY:			clean fclean re test bonus test_bonus
