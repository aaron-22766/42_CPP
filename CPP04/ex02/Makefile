# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/14 11:21:33 by arabenst          #+#    #+#              #
#    Updated: 2023/09/13 10:08:11 by arabenst         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	aanimal

INCDIR		:=	./include
SRCDIR		:=	./src
BUILDDIR	:=	./build

INCS		:=	$(wildcard $(INCDIR)/*.hpp)
SRCS		:=	$(wildcard $(SRCDIR)/*.cpp)
OBJS		:=	$(addprefix $(BUILDDIR)/, $(notdir $(SRCS:.cpp=.o)))
DEPS		:=	$(OBJS:.o=.d)

CC			:=	c++
INCFLAGS	:=	-I $(INCDIR)
CPPFLAGS	:=	-Wall -Werror -Wextra -std=c++98 -MMD $(INCFLAGS)

RM			:=	rm
RMFLAGS		:=	-rf

$(NAME): $(OBJS)
	$(CC) -o $@ $^

-include $(DEPS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(@D)
	$(CC) -c -o $@ $< $(CPPFLAGS)

all: $(NAME)

clean:
	$(RM) $(RMFLAGS) $(BUILDDIR)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

re: fclean all

.PHONY: all clean fclean re