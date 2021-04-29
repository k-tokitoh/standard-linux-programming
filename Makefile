CC      = gcc
CFLAGS  = -Wall
SOURCES = $(wildcard commands/*/*.c)
TARGETS = $(SOURCES:%.c=%)

all: $(TARGETS)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

test: all
	tests/index.sh

clean:
	rm $(TARGETS)
