NAME = scalar_converter
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SOURCES = main.cpp 
OBJECTS = $(SOURCES:.cpp=.o)

%.o: %.cpp
        $(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
        $(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

clean:
        rm -f $(OBJECTS)

fclean: clean
        rm -f $(NAME)

all: $(NAME)

re: fclean all

.PHONY: all clean fclean re