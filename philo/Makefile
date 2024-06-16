NAME = philo
BONUS_NAME = philo_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread

SRCS = ./src/philosophers.c  ./src/mini_lib.c ./src/parrsing.c ./src/free_err.c ./src/ft_itoa_nosigne.c 
BONUS_SRCS = bonus/philosophers_bonus.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)



HEADERS = ./include

# COLOR #
GREEN	= \033[38;5;76m
RED		= \033[38;5;160m
YELLOW	= \033[38;5;226m
ORANGE	= \033[38;5;202m
PURPLE	= \033[38;5;213m
LBLUE	= \033[38;5;51m
BLUE	= \033[38;5;117m
INDI	= \033[38;5;99m
RESET	= \033[00m

all: $(NAME)


$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -I$(HEADERS) -o $@ $(OBJS) -L ${LIBFTDIR} -lft
	@printf "$(BLUE)\n\n\n"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢟⣛⣭⣵⣶⣶⣬⣭⣭⣭⣝⡛⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⣫⣵⣾⣿⣿⣿⣿⣿⣿⣿⡿⣏⢻⣟⢿⣷⣬⡙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿"
	@echo "⣿⣿⣿⣿⣿⣿⡿⢫⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣜⡜⣿⣆⢿⡜⣿⣎⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿"
	@echo "⣿⣿⣿⣿⣿⠟⣴⣿⣿⡇⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⣿⡎⣿⢸⡟⣾⢿⡎⢻⣧⡹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿"
	@echo "⣿⣿⣿⣿⠏⣼⣿⣿⢡⣹⡟⣿⣿⣿⡿⠟⠛⠋⠉⠁⠀⠀⠉⠈⠁⠙⠘⠇⢠⣿⣧⢹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿"
	@echo "⣿⣿⣿⠇⣼⣿⣿⣿⣾⢿⣷⠙⠋⠁⠀⠀⠀⠀⠀⢀⣀⣠⣤⣤⣴⣶⣶⣶⡶⢲⣶⣶⣬⣭⣟⣛⣿⢛⣭⣛⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿"
	@echo "⣿⣿⡿⢸⣿⡟⣿⡆⠿⠂⠀⠀⠀⣀⣀⣤⣴⣶⣿⣿⣿⣿⣿⣿⣿⠿⠋⠁⣴⣿⣟⣖⣉⠻⠿⣿⡇⣾⣿⣿⣷⡝⢿⣿⣿⣿⣿⣿⣿⣿"
	@echo "⣿⣿⡇⣾⣿⣧⢻⠏⠀⢀⣠⣴⣿⣏⣥⡾⠾⢉⣛⠛⠛⠉⠉⠁⠀⠀⠐⠛⠉⠙⠋⠋⠩⣝⣳⣾⡇⣿⣿⣿⣿⣿⢠⣝⢿⣿⣿⣿⣿⣿"
	@echo "⣿⣿⡇⣿⣿⣿⠇⣠⡶⢋⣡⣤⠏⠉⢁⣴⣿⣿⣿⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢾⣷⣦⣿⣿⠧⢻⣿⣿⣿⣿⡄⣿⣆⢻⣿⣿⣿⣿"
	@echo "⣿⣿⣿⡘⢋⣵⣾⣿⡿⠛⠉⠀⠀⠀⣼⣿⣿⣿⣿⣿⣷⡀⠀⣦⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⡛⢉⢷⡄⢻⣿⣿⡿⠇⡿⡇⠀⣿⣿⣿⣿"
	@echo "⣿⡿⢋⣴⣿⠿⠋⠉⠀⠀⠀⠀⠀⢰⣿⣿⣿⣿⣿⣿⣿⣷⡀⢸⣷⡀⠀⠀⠀⠀⠀⠀⠀⢀⡈⠈⢣⢿⠠⣤⠩⣶⡆⣇⣠⠀⣿⣿⣿⣿"
	@echo "⢋⡴⣫⢉⠄⠀⠀⠀⠀⠀⠀⣼⠀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣧⢸⠿⢛⣀⠘⣄⠀⠀⠀⠀⠈⠻⡟⢺⡼⡇⣿⡀⢙⣇⢿⡟⣼⣿⣿⣿⣿"
	@echo "⣫⡾⠛⠁⠀⣴⠀⠀⠀⠀⠀⣟⡂⡻⠿⣿⣿⣿⣿⣿⣿⣿⣋⣴⣾⠿⢿⠆⢿⡄⠀⠀⠀⠐⣦⣄⡸⢱⡇⣿⠀⠀⠹⠈⢼⣿⣿⣿⣿⣿"
	@echo "⣿⢃⢂⢊⣾⡇⠀⠀⠀⡄⢰⣿⣧⣿⣿⣶⣶⣿⣟⢻⣿⣿⣿⠋⢁⢤⡤⠂⣸⠿⠀⡆⠀⠌⠈⡿⠡⠟⣃⣭⣶⣾⣿⣷⣶⣍⡻⢿⣿⣿"
	@echo "⢁⣶⠟⢺⡏⠀⠀⠀⠀⣷⢸⡟⢋⣩⣄⣉⢹⣿⣿⣾⣿⣿⣿⣷⣯⣄⡲⠖⠩⢂⢲⡇⠉⠘⡧⢀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⢙⣿"
	@echo "⢸⣩⢘⢸⡇⢠⢇⣤⠀⢿⣿⢷⣿⣿⣿⣿⣿⣿⣿⣦⣉⡿⠿⠟⣛⣭⣦⣾⣷⣿⢸⡇⠸⣣⢀⠀⣦⣹⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢸⣿"
	@echo "⣦⢻⣸⣼⡱⣿⡄⣤⠀⢸⣿⠰⠆⣍⢉⣭⣭⣭⣭⣴⣶⣶⣿⣿⣿⣿⣿⣿⢟⡁⣸⡇⠞⠁⠘⣤⡿⠿⠟⣛⣭⣭⣶⣾⣿⣿⣿⣅⣿⣿"
	@echo "⣾⣀⠿⣅⣉⢾⣧⢻⡁⠀⢿⡇⢦⣿⣿⣿⣿⣿⡿⠿⢟⣛⣻⣭⣭⣭⣭⣁⣌⢠⡿⢠⣖⡄⣄⠀⠁⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⠻"
	@echo "⠰⢭⣓⠦⣭⣥⠙⣧⣙⠦⡌⢿⡄⠙⠗⢙⣭⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⡿⣣⡞⢁⠸⠟⣽⡏⢸⢀⢰⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣇⠀"
	@echo "⣿⣶⣬⣭⣙⣛⣛⣛⣛⣓⡲⣌⠻⣦⡘⢾⣿⣿⣿⣿⣿⣿⣿⡿⠛⠛⣩⠞⠉⣠⣿⣿⣳⢷⣷⠈⠻⠾⠈⢟⣛⣛⣋⣿⣿⣿⣿⣿⣿⣦"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠈⠙⠲⠬⣭⣉⣙⣋⣠⣭⠴⠶⠋⠁⢠⣾⡿⣿⣿⣏⣿⠃⠀⠸⡇⢠⢹⣿⣿⣿⣿⡿⣿⣿⣿⣿⣿"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⠀⠀⣾⣷⣶⣶⠤⠀⠀⠶⡀⢀⠄⢠⢿⣟⣴⣿⡿⣼⠃⠀⠀⠀⠈⡉⢘⠛⣛⣫⣤⣶⣿⣿⣿⡟⣿"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣇⠀⠀⠀⠀⠻⣟⣛⠿⣦⣤⣠⡄⠀⠌⠠⢱⡟⣼⠿⠛⣡⠁⠀⠀⠀⠀⠀⠃⢨⣇⣿⣿⣿⣿⣿⡿⢋⣾⣯"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀⢀⣄⠈⢻⣿⣷⣾⣭⣛⣻⣧⣀⣛⣨⣴⣾⣿⣷⣆⠀⠀⠀⠀⠀⠀⠀⠀⠩⡙⠛⠋⠁⠈⠙⠛⠉"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣇⠀⢾⣿⠇⠈⣿⣿⣿⣿⣿⣿⡇⣿⣿⣿⣿⣿⣿⡟⢻⡆⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠁⠀⠀⠈⠻⢿⣿⣿⣿⡇⣿⣿⣿⣿⡿⢋⢠⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣤⣄"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⠀⠀⣀⡀⢸⣦⡒⠨⠛⠿⣷⡹⣿⣟⣫⣬⣭⣼⣿⣿⣷⣄⣀⣀⣀⣀⣀⣀⣀⣈⣭⣥⣿⣿⣿⣿"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡆⢘⣿⣧⣀⣻⣿⣦⣽⣿⣿⡷⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿"
	
%.o: %.c
	@printf "$(LBLUE)[Compilation]$(RESET) In progress... $(GREEN)$<" && \
	$(CC) $(CFLAGS) -I$(HEADERS) -c $< -o $@ && \
	printf "\r$(LBLUE)[Compilation]$(RESET) Completed   ... $(GREEN)$<" && \
	printf " $(LBLUE)[$(RESET)$(CC)$(LBLUE)/]$(RESET)\n"

bonus :  ${BONUS_NAME}

${BONUS_NAME} : $(BONUS_OBJS)
	@make -C $(LIBFTDIR)
	@$(CC) $(CFLAGS) -I$(HEADERS) -o ${BONUS_NAME} $(BONUS_OBJS)
	@printf "$(BLUE)\n\n\n"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢟⣛⣭⣵⣶⣶⣬⣭⣭⣭⣝⡛⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⣫⣵⣾⣿⣿⣿⣿⣿⣿⣿⡿⣏⢻⣟⢿⣷⣬⡙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿"
	@echo "⣿⣿⣿⣿⣿⣿⡿⢫⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣜⡜⣿⣆⢿⡜⣿⣎⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿"
	@echo "⣿⣿⣿⣿⣿⠟⣴⣿⣿⡇⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⣿⡎⣿⢸⡟⣾⢿⡎⢻⣧⡹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿"
	@echo "⣿⣿⣿⣿⠏⣼⣿⣿⢡⣹⡟⣿⣿⣿⡿⠟⠛⠋⠉⠁⠀⠀⠉⠈⠁⠙⠘⠇⢠⣿⣧⢹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿"
	@echo "⣿⣿⣿⠇⣼⣿⣿⣿⣾⢿⣷⠙⠋⠁⠀⠀⠀⠀⠀⢀⣀⣠⣤⣤⣴⣶⣶⣶⡶⢲⣶⣶⣬⣭⣟⣛⣿⢛⣭⣛⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿"
	@echo "⣿⣿⡿⢸⣿⡟⣿⡆⠿⠂⠀⠀⠀⣀⣀⣤⣴⣶⣿⣿⣿⣿⣿⣿⣿⠿⠋⠁⣴⣿⣟⣖⣉⠻⠿⣿⡇⣾⣿⣿⣷⡝⢿⣿⣿⣿⣿⣿⣿⣿"
	@echo "⣿⣿⡇⣾⣿⣧⢻⠏⠀⢀⣠⣴⣿⣏⣥⡾⠾⢉⣛⠛⠛⠉⠉⠁⠀⠀⠐⠛⠉⠙⠋⠋⠩⣝⣳⣾⡇⣿⣿⣿⣿⣿⢠⣝⢿⣿⣿⣿⣿⣿"
	@echo "⣿⣿⡇⣿⣿⣿⠇⣠⡶⢋⣡⣤⠏⠉⢁⣴⣿⣿⣿⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢾⣷⣦⣿⣿⠧⢻⣿⣿⣿⣿⡄⣿⣆⢻⣿⣿⣿⣿"
	@echo "⣿⣿⣿⡘⢋⣵⣾⣿⡿⠛⠉⠀⠀⠀⣼⣿⣿⣿⣿⣿⣷⡀⠀⣦⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⡛⢉⢷⡄⢻⣿⣿⡿⠇⡿⡇⠀⣿⣿⣿⣿"
	@echo "⣿⡿⢋⣴⣿⠿⠋⠉⠀⠀⠀⠀⠀⢰⣿⣿⣿⣿⣿⣿⣿⣷⡀⢸⣷⡀⠀⠀⠀⠀⠀⠀⠀⢀⡈⠈⢣⢿⠠⣤⠩⣶⡆⣇⣠⠀⣿⣿⣿⣿"
	@echo "⢋⡴⣫⢉⠄⠀⠀⠀⠀⠀⠀⣼⠀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣧⢸⠿⢛⣀⠘⣄⠀⠀⠀⠀⠈⠻⡟⢺⡼⡇⣿⡀⢙⣇⢿⡟⣼⣿⣿⣿⣿"
	@echo "⣫⡾⠛⠁⠀⣴⠀⠀⠀⠀⠀⣟⡂⡻⠿⣿⣿⣿⣿⣿⣿⣿⣋⣴⣾⠿⢿⠆⢿⡄⠀⠀⠀⠐⣦⣄⡸⢱⡇⣿⠀⠀⠹⠈⢼⣿⣿⣿⣿⣿"
	@echo "⣿⢃⢂⢊⣾⡇⠀⠀⠀⡄⢰⣿⣧⣿⣿⣶⣶⣿⣟⢻⣿⣿⣿⠋⢁⢤⡤⠂⣸⠿⠀⡆⠀⠌⠈⡿⠡⠟⣃⣭⣶⣾⣿⣷⣶⣍⡻⢿⣿⣿"
	@echo "⢁⣶⠟⢺⡏⠀⠀⠀⠀⣷⢸⡟⢋⣩⣄⣉⢹⣿⣿⣾⣿⣿⣿⣷⣯⣄⡲⠖⠩⢂⢲⡇⠉⠘⡧⢀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⢙⣿"
	@echo "⢸⣩⢘⢸⡇⢠⢇⣤⠀⢿⣿⢷⣿⣿⣿⣿⣿⣿⣿⣦⣉⡿⠿⠟⣛⣭⣦⣾⣷⣿⢸⡇⠸⣣⢀⠀⣦⣹⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢸⣿"
	@echo "⣦⢻⣸⣼⡱⣿⡄⣤⠀⢸⣿⠰⠆⣍⢉⣭⣭⣭⣭⣴⣶⣶⣿⣿⣿⣿⣿⣿⢟⡁⣸⡇⠞⠁⠘⣤⡿⠿⠟⣛⣭⣭⣶⣾⣿⣿⣿⣅⣿⣿"
	@echo "⣾⣀⠿⣅⣉⢾⣧⢻⡁⠀⢿⡇⢦⣿⣿⣿⣿⣿⡿⠿⢟⣛⣻⣭⣭⣭⣭⣁⣌⢠⡿⢠⣖⡄⣄⠀⠁⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⠻"
	@echo "⠰⢭⣓⠦⣭⣥⠙⣧⣙⠦⡌⢿⡄⠙⠗⢙⣭⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⡿⣣⡞⢁⠸⠟⣽⡏⢸⢀⢰⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣇⠀"
	@echo "⣿⣶⣬⣭⣙⣛⣛⣛⣛⣓⡲⣌⠻⣦⡘⢾⣿⣿⣿⣿⣿⣿⣿⡿⠛⠛⣩⠞⠉⣠⣿⣿⣳⢷⣷⠈⠻⠾⠈⢟⣛⣛⣋⣿⣿⣿⣿⣿⣿⣦"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠈⠙⠲⠬⣭⣉⣙⣋⣠⣭⠴⠶⠋⠁⢠⣾⡿⣿⣿⣏⣿⠃⠀⠸⡇⢠⢹⣿⣿⣿⣿⡿⣿⣿⣿⣿⣿"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⠀⠀⣾⣷⣶⣶⠤⠀⠀⠶⡀⢀⠄⢠⢿⣟⣴⣿⡿⣼⠃⠀⠀⠀⠈⡉⢘⠛⣛⣫⣤⣶⣿⣿⣿⡟⣿"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣇⠀⠀⠀⠀⠻⣟⣛⠿⣦⣤⣠⡄⠀⠌⠠⢱⡟⣼⠿⠛⣡⠁⠀⠀⠀⠀⠀⠃⢨⣇⣿⣿⣿⣿⣿⡿⢋⣾⣯"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀⢀⣄⠈⢻⣿⣷⣾⣭⣛⣻⣧⣀⣛⣨⣴⣾⣿⣷⣆⠀⠀⠀⠀⠀⠀⠀⠀⠩⡙⠛⠋⠁⠈⠙⠛⠉"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣇⠀⢾⣿⠇⠈⣿⣿⣿⣿⣿⣿⡇⣿⣿⣿⣿⣿⣿⡟⢻⡆⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠁⠀⠀⠈⠻⢿⣿⣿⣿⡇⣿⣿⣿⣿⡿⢋⢠⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣤⣄"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⠀⠀⣀⡀⢸⣦⡒⠨⠛⠿⣷⡹⣿⣟⣫⣬⣭⣼⣿⣿⣷⣄⣀⣀⣀⣀⣀⣀⣀⣈⣭⣥⣿⣿⣿⣿"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡆⢘⣿⣧⣀⣻⣿⣦⣽⣿⣿⡷⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿"

clean:
	@for obj in $(OBJS); do \
		printf "$(RED)Cleaning $(NAME)...  Removing $$obj... " && \
		sleep 0.01 && \
		rm -f $$obj && \
		printf "\r"; \
	done
	@for obj in $(BONUS_OBJS); do \
		printf "$(RED)Cleaning $(BONUS_NAME)...  Removing $$obj... " && \
		sleep 0.01 && \
		rm -f $$obj && \
		printf "\r"; \
	done

	@printf "                                                                                                          \r$(GREEN)$(NAME) is Clean\n$(RESET)"

	
fclean: clean
	@rm -f $(NAME) $(BONUS_NAME) 
	
re: fclean all

.PHONY : all clean fclean re bonus