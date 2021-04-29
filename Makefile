
# this Makefile is used by nmake when compiling on windows

BIN = processes_pipes.exe
OBJ = processes_pipes.obj

all: $(BIN)

$(BIN): $(OBJ)
	link $(LFLAGS) $** /out:processes_pipes.exe

clean:
	-del $(BIN) $(OBJ)
