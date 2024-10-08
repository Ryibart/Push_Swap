# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/18 13:24:58 by rtammi            #+#    #+#              #
#    Updated: 2024/10/08 16:13:18 by rtammi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := push_swap

CC          := cc

CFLAGS      := -Wall -Wextra -Werror
DEPSFLAGS   := -MMD -MP
HEADERFLAG  := -I includes/
ECHOFLAG	:= 

RM          := rm -rf

LIBFT		:= ./libft
LIBFT_DIR	:= ./libft/library

# Directories
OBJ_DEP_DIR	:= objects_and_dependencies

# Source directories
SRC_DIRS    := sources sources/rules sources/utils
SRC_DIRS_OBJ := $(addprefix $(OBJ_DEP_DIR)/, $(SRC_DIRS))

# Source files
SOURCES	 := 	push_swap.c \
				add_elements.c \
				main.c \
				verify_args.c

RULES	 := 	push.c \
				rotate.c \
				swap.c		\
				reverse_rotate.c

UTILS	 := 	error_handler.c \
				debug.c
				

SRCS        := $(addprefix sources/, $(SOURCES)) \
               $(addprefix sources/rules/, $(RULES)) \
               $(addprefix sources/utils/, $(UTILS)) 

# Object and Dependency Files
OBJS        := $(SRCS:%.c=$(OBJ_DEP_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

# Color and Style Codes
YELLOW      := \033[33m
GREEN       := \033[32m
BLUE        := \033[34m
RED         := \033[31m
BOLD        := \033[1m
NC          := \033[0m

# Message Helpers
linking_message      	= @echo $(ECHOFLAG) "$(YELLOW)🔗 Linking $1...$(NC)"
build_success_message	= @echo $(ECHOFLAG) "$(GREEN)🥳$(BOLD)$1 built successfully!$(NC)"
compile_message    		= @echo $(ECHOFLAG) "$(BLUE)🤔 Compiling $<...$(NC)"
compile_success_message	= @echo $(ECHOFLAG) "$(GREEN)🥳 $(BOLD)Compiled$< successfully!$(NC)"
compile_fail_message 	= @echo $(ECHOFLAG) "$(RED)💥 $(BOLD)Failed to compile $<!$(NC)"
clean_message        	= @echo $(ECHOFLAG) "$(YELLOW)🚮 Cleaning up...$(NC)"
clean_success_message	= @echo $(ECHOFLAG) "$(GREEN)🧹 $(BOLD)Cleaned up object and dependency files!$(NC)"
fclean_message        	= @echo $(ECHOFLAG) "$(YELLOW)😱 Removing Push_swap..$(NC)"
fclean_success_message	= @echo $(ECHOFLAG) "$(GREEN)🫡 $(BOLD)Push_swap removed!$(NC)"

# Rules
all: libft create_dirs $(NAME)

libft:
	@$(MAKE) -s -C ./libft

$(NAME): $(OBJS)
	$(call linking_message, $(NAME))
	@$(CC) $(CFLAGS) $(OBJS) -L $(LIBFT_DIR) -lft -o $(NAME)
	$(call build_success_message, $(NAME))

# Object file compilation
$(OBJ_DEP_DIR)/%.o: %.c
	$(call compile_message)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(DEPSFLAGS) $(HEADERFLAG) -c $< -o $@ || { $(call compile_fail_message); exit 1; }
	$(call compile_success_message)

# Create directories
create_dirs:
	@mkdir -p $(OBJ_DEP_DIR)

clean:
	$(call clean_message)
	@$(RM) $(OBJ_DEP_DIR)
	@$(MAKE) -s -C $(LIBFT) clean
	$(call clean_success_message)

fclean: clean
	$(call fclean_message)
	@$(RM) $(NAME)
	@$(MAKE) -s -C $(LIBFT) fclean
	$(call fclean_success_message)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re create_dirs libft