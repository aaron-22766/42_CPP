# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 12:40:42 by arabenst          #+#    #+#              #
#    Updated: 2023/10/05 11:51:29 by arabenst         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	array

INCDIR		:=	./include
SRCDIR		:=	./src
BUILDDIR	:=	./build

INCS		:=	$(wildcard $(INCDIR)/*.hpp) $(wildcard $(INCDIR)/*.tpp)
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

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp $(INCS)
	mkdir -p $(@D)
	$(CC) -c -o $@ $< $(CPPFLAGS)

all: $(NAME)

clean:
	$(RM) $(RMFLAGS) $(BUILDDIR)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

re: fclean all

.PHONY: all clean fclean re