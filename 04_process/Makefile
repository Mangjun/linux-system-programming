SRCS = $(wildcard *.c)
TARGETS = $(SRCS:.c=)
CFLAGS = -Wall -Werror -pthread

all: $(TARGETS)

% : %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf $(TARGETS)

.PHONY: clean
