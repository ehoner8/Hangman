CC = clang
CFLAGS = -Werror -Wall -Wextra -Wconversion -Wdouble-promotion -Wstrict-prototypes -pedantic
LFLAGS =
EXEC = hangman
HEADERS = hangman_helpers.h

all: $(EXEC) tests


$(EXEC): $(EXEC).o hangman_helpers.o
	$(CC) $^ $(LFLAGS) -o $@

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $<

tests: test_functionality test_helpers

test_functionality:
	bash test_functionality.sh

test_helpers: hangman_helpers.o test_helpers.o
	$(CC) $^ $(LFLAGS) -o $@
	./test_helpers	

clean:
	rm -rf $(EXEC) *.o

format:
	clang-format -i -style=file *.[ch]

.PHONY: all clean format
