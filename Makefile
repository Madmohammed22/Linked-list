CC = gcc
CFLAGS = -Wall -Wextra

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
TARGET = myprogram

.PHONY: all clean fclean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET) *~