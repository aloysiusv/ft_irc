# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 00:50:14 by estoffel          #+#    #+#              #
#    Updated: 2022/11/29 08:13:17 by bbrassar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ircserv

CC		=	c++

# DEFINES += -DVERSION_COMMIT="$(COMMIT)"
# DEFINES += -DBUILD_DATE="$(BUILD_DATE)"
DEFINES += -D_GLIBCXX_DEBUG

FLAGS	=	-Wall -Wextra -Werror -Iincl -g3 -MMD -MP -std=c++98 $(DEFINES)

# main
SRC		= bbrassar.cpp

# classes
SRC		+= Recipient.cpp
SRC		+= Client.cpp
SRC		+= CommandContext.cpp
SRC		+= Channel.cpp
SRC		+= Server.cpp
SRC		+= CommandMap.cpp
SRC		+= Reply.cpp
SRC		+= OperatorEntry.cpp
SRC		+= wildcard.cpp
SRC		+= Logger.cpp

# commands
SRC		+= cmds/cmd_user.cpp
SRC		+= cmds/cmd_nick.cpp
SRC		+= cmds/cmd_pass.cpp
SRC		+= cmds/cmd_quit.cpp
SRC		+= cmds/cmd_part.cpp
SRC		+= cmds/cmd_join.cpp
SRC		+= cmds/cmd_motd.cpp
SRC		+= cmds/cmd_oper.cpp
SRC		+= cmds/cmd_die.cpp
SRC		+= cmds/cmd_kill.cpp
SRC		+= cmds/cmd_privmsg.cpp
SRC		+= cmds/cmd_notice.cpp
SRC		+= cmds/cmd_msg_common.cpp
# SRC		+= cmds/cmd_mode.cpp

OBJ		:=	$(addprefix ./obj/,$(SRC:%.cpp=%.o))

DEP		=	$(OBJ:%.o=%.d)

RM		=	rm -rf

# COMMIT	:= $(shell git rev-parse --short HEAD)
# BUILD_DATE := $(shell date +'%Y-%m-%d %H:%M:%S')

all: $(NAME)

-include $(DEP)

./obj/%.o: ./src/%.cpp
	@mkdir -p $(@D)
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)
	@printf "\n"
	@printf "\n"
	@echo "   🌼\033[1;97m I R C S E R V  C R E A T E D  W I T H  S U C C E S S 🌼\e[0m"
	@printf "\n"
	@echo "				x"
	@printf "\n"
	@echo "		✨	~ \033[1;97mBen Enora Liana\e[0m ~	✨"
	@printf "\n"
	@printf "\n"

clean:
	$(RM) obj/
	@printf "\n"
	@echo "💧\033[1;97m E V E R Y T H I N G  I S  C L E A N E D 💧\e[0m"
	@printf "\n"

fclean:
	$(RM) obj/
	$(RM) $(NAME)
	@printf "\n"
	@echo "💧\033[1;97m E V E R Y T H I N G  I S  C L E A N E D 💧\e[0m"
	@printf "\n"

re: fclean all

.PHONY: all clean fclean re
