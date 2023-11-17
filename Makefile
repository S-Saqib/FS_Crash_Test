CC = gcc
CFLAGS = -Wall -Wextra
SRC_FILES = blk_writer.c file_create.c file_remove.c file_parse.c
EXE_FILES = $(patsubst %.c,%,$(SRC_FILES))

all: $(EXE_FILES)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(EXE_FILES)
