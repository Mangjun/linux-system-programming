SRCS = $(wildcard *.c)
TARGETS = $(SRCS:.c=)
CFLAGS = -Wall -Werror

all: $(TARGETS)

% : %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf $(TARGETS)

.PHONY: clean
