#-I folder for headers
NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
#usually CCPFLAGS by convention
INCL		= -I ./ -I libft -I ft_printf
LIBFT_A 	= libft/libft.a
FT_PRINTF_A	= ft_printf/libftprintf.a
ALGO_TESTER	= algo_tester
OP_TESTER	= op_tester
PAR_TOK_TESTER	= par_tok_tester
PARSER_TESTER	= parser_tester
STACK_TESTER	= stack_tester
FLAG_TESTER		= flag_tester

#list of .c files to convert into .o object files
SRC					=	./parser/parse.c \
						./parser/tokenizer.c \
						./stacks/stack_operations_1.c \
						./stacks/stack_operations_2.c \
						./stacks/stack_operations_3.c \
						./operations/swap.c \
						./operations/push.c \
						./operations/rotate.c \
						./operations/reverse_rotate.c \
						./algorithms/simple.c \
						./algorithms/medium.c \
						./algorithms/chunk_utils.c \
						./algorithms/complex.c \
						./algorithms/adaptive.c \
						./algorithms/less_than_five.c \
						./algorithms/algorithm_selector.c \
						error.c \
						flag_checker.c \
						disorder_metric.c \
						push_swap.c

LIBFT_SRC			=	ft_atoi.c \
						ft_bzero.c \
						ft_calloc.c \
						ft_isalnum.c \
						ft_isalpha.c \
						ft_isascii.c \
						ft_isdigit.c \
						ft_isprint.c \
						ft_itoa.c \
						ft_lstadd_back.c \
						ft_lstadd_front.c \
						ft_lstclear.c \
						ft_lstdelone.c \
						ft_lstiter.c \
						ft_lstlast.c \
						ft_lstmap.c \
						ft_lstnew.c \
						ft_lstsize.c \
						ft_memchr.c \
						ft_memcmp.c \
						ft_memcpy.c \
						ft_memmove.c \
						ft_memset.c \
						ft_putchar_fd.c \
						ft_putendl_fd.c \
						ft_putnbr_fd.c \
						ft_putstr_fd.c \
						ft_split.c \
						ft_strchr.c \
						ft_strdup.c \
						ft_striteri.c \
						ft_strjoin.c \
						ft_strlcat.c \
						ft_strlcpy.c \
						ft_strlen.c \
						ft_strmapi.c \
						ft_strncmp.c \
						ft_strnstr.c \
						ft_strrchr.c \
						ft_strtrim.c \
						ft_substr.c \
						ft_tolower.c \
						ft_toupper.c

FT_PRINTF_SRC		=	ft_printf.c\
						ft_print_char.c\
						ft_print_str.c\
						ft_print_int.c\
						ft_print_deci.c\
						ft_print_hexa.c\
						ft_print_ptr.c\
						ft_print_percent.c\
						ft_handle_specifier.c

AL_SRC				=	./tester/algorithms_tester.c \
						./stacks/stack_operations_1.c \
						./stacks/stack_operations_2.c \
						./stacks/stack_operations_3.c \
						./operations/swap.c \
						./operations/push.c \
						./operations/rotate.c \
						./operations/reverse_rotate.c \
						./algorithms/simple.c \
						./algorithms/medium.c \
						./algorithms/chunk_utils.c \
						./algorithms/complex.c \
						./algorithms/adaptive.c \
						./algorithms/less_than_five.c \
						disorder_metric.c \
						error.c


OP_SRC				=	./tester/operations_tester.c \
						./stacks/stack_operations_1.c \
						./stacks/stack_operations_2.c \
						./stacks/stack_operations_3.c \
						./operations/swap.c \
						./operations/push.c \
						./operations/rotate.c \
						./operations/reverse_rotate.c \
						error.c

PT_SRC				=	./tester/parser_and_tokenizer_tester.c \
						./stacks/stack_operations_1.c \
						./stacks/stack_operations_2.c \
						./stacks/stack_operations_3.c \
						./operations/rotate.c \
						./operations/reverse_rotate.c \
						./parser/parse.c \
						./parser/tokenizer.c \
						error.c

PA_SRC				=	./tester/parser_tester.c \
						./stacks/stack_operations_1.c \
						./stacks/stack_operations_2.c \
						./stacks/stack_operations_3.c \
						./operations/rotate.c \
						./operations/reverse_rotate.c \
						./parser/parse.c \
						error.c

ST_SRC				=	./tester/stack_tester.c \
						./stacks/stack_operations_1.c \
						./stacks/stack_operations_2.c \
						./stacks/stack_operations_3.c \
						./operations/rotate.c \
						./operations/reverse_rotate.c \
						error.c

FL_SRC				=	flag_checker.c

LIBFT_INPUTS		=	$(addprefix libft/,$(LIBFT_SRC)) \
						libft/libft.h libft/Makefile

FT_PRINTF_INPUTS	=	$(addprefix ft_printf/,$(FT_PRINTF_SRC)) \
						ft_printf/ft_printf.h ft_printf/Makefile \
						libft/libft.h

HEADER				=	./libft/libft.h \
						./ft_printf/ft_printf.h \
						push_swap.h

#same name as everything with .c in SRC but with .o instead
OBJ		= $(SRC:.c=.o)

OBJ_AL	= $(AL_SRC:.c=.o)
OBJ_OP	= $(OP_SRC:.c=.o)
OBJ_PT	= $(PT_SRC:.c=.o)
OBJ_PA	= $(PA_SRC:.c=.o)
OBJ_ST	= $(ST_SRC:.c=.o)
OBJ_FL	= $(FL_SRC:.c=.o)

#-f forces
RM		= -rm -f

# @ hides the command from the command line
# Main rule
#all : libft ft_printf $(NAME)
all : $(NAME)

#ft_printf :
#	@$(MAKE) -C ./ft_printf

$(FT_PRINTF_A): $(FT_PRINTF_INPUTS)
	@$(MAKE) -C ft_printf

#libft : 
#	@$(MAKE) -C ./libft

$(LIBFT_A): $(LIBFT_INPUTS)
	@$(MAKE) -C libft

#compiling .c files into object files: ... $< indicates source; ... $@ indicates destination (source $< destination $@)
%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) $(INCL) -c $< -o $@

# Compiling the program
$(NAME) : $(OBJ) $(LIBFT_A) $(FT_PRINTF_A)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_A) $(FT_PRINTF_A) -o $(NAME)

$(ALGO_TESTER) : $(OBJ_AL) $(LIBFT_A) $(FT_PRINTF_A)
	@$(CC) $(CFLAGS) $(OBJ_AL) $(LIBFT_A) $(FT_PRINTF_A) -o $(ALGO_TESTER)
$(OP_TESTER) : $(OBJ_OP) $(LIBFT_A) $(FT_PRINTF_A)
	@$(CC) $(CFLAGS) $(OBJ_OP) $(LIBFT_A) $(FT_PRINTF_A) -o $(OP_TESTER)
$(PAR_TOK_TESTER) : $(OBJ_PT) $(LIBFT_A) $(FT_PRINTF_A)
	@$(CC) $(CFLAGS) $(OBJ_PT) $(LIBFT_A) $(FT_PRINTF_A) -o $(PAR_TOK_TESTER)
$(PARSER_TESTER) : $(OBJ_PA) $(LIBFT_A) $(FT_PRINTF_A)
	@$(CC) $(CFLAGS) $(OBJ_PA) $(LIBFT_A) $(FT_PRINTF_A) -o $(PARSER_TESTER)
$(STACK_TESTER) : $(OBJ_ST) $(LIBFT_A) $(FT_PRINTF_A)
	@$(CC) $(CFLAGS) $(OBJ_ST) $(LIBFT_A) $(FT_PRINTF_A) -o $(STACK_TESTER)
$(FLAG_TESTER) : $(OBJ_ST) $(LIBFT_A) $(FT_PRINTF_A)
	@$(CC) $(CFLAGS) $(OBJ_ST) $(LIBFT_A) $(FT_PRINTF_A) -o $(FLAG_TESTER)

testers : $(ALGO_TESTER) $(OP_TESTER) $(PAR_TOK_TESTER) $(PARSER_TESTER) $(STACK_TESTER) $(FLAG_TESTER)

# Deletes object files
clean :
	@$(RM) $(OBJ)
	@$(MAKE) -C libft clean
	@$(MAKE) -C ft_printf clean

clean_al :
	@$(RM) $(OBJ_AL)
clean_op :
	@$(RM) $(OBJ_OP)
clean_pt :
	@$(RM) $(OBJ_PT)
clean_pa :
	@$(RM) $(OBJ_PA)
clean_st :
	@$(RM) $(OBJ_ST)
clean_fl :
	@$(RM) $(OBJ_FL)
clean_testers : clean_al clean_op clean_pt clean_pa clean_st clean_fl

# Deletes object files and exec
fclean :
	@$(RM) $(OBJ)
	@$(RM) $(NAME) 
	@$(MAKE) -C libft fclean
	@$(MAKE) -C ft_printf fclean

fclean_al :
	@$(RM) $(OBJ_AL)
	@$(RM) $(ALGO_TESTER)
fclean_op :
	@$(RM) $(OBJ_OP)
	@$(RM) $(OP_TESTER)
fclean_pt :
	@$(RM) $(OBJ_PT)
	@$(RM) $(PAR_TOK_TESTER)
fclean_pa :
	@$(RM) $(OBJ_PA)
	@$(RM) $(PARSER_TESTER)
fclean_st :
	@$(RM) $(OBJ_ST)
	@$(RM) $(STACK_TESTER)
fclean_fl :
	@$(RM) $(OBJ_FL)
	@$(RM) $(FLAG_TESTER)
fclean_testers : fclean_al fclean_op fclean_pt fclean_pa fclean_st fclean_fl

# Deletes object files and exec, and then compiles again: same file coz it's a dependency, not a shell command
#done like this they two procedures are sequential, so even with a -j flag after "make" in the terminal the process will be working
#otherwise it could end with fclean and all running at the same time
re :
	$(MAKE) fclean
	$(MAKE) all

# Avoid conflict with potential files with the same name: doesn't treat them as files, but rather as commands
.PHONY : all clean fclean re clean_al clean_op clean_pt clean_pa clean_st clean_fl fclean_al fclean_op fclean_pt fclean_pa fclean_st fclean_fl testers clean_testers fclean_testers
