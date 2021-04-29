
# this Makefile is used by GNU make when compiling on Linux and MacOS

BIN = processes_pipes
OBJ = processes_pipes.o

CFLAGS = -Wall -Wextra -g

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) -o $@ $(LDFLAGS) $^

clean:
	$(RM) $(BIN) $(OBJ)
