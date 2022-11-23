cc = gcc
CFLAGS = -fPIC -std=c99 -pedantic -Werror -Wall -Wextra -Wvla -g

SRC = tree.c
OBJS = $(SRC:.c=.o)
LIB = libbinary_tree.a

all: library

library: $(LIB)

$(LIB): $(OBJS)
	ar crs $@ $^

clean:
	$(RM) *.o *.a
