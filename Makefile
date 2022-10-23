NAME  = Lexsis

CC    = clang
FLGS  = -std=c11 -O3 -Wall -Wextra -pedantic

SRC   = ./Source 
OUT   = ./Output
BIN   = $(OUT)/$(NAME).exe

DIRS  = $(SRC)
SRCS  = $(foreach D,$(DIRS),$(wildcard $(D)/*.c))
OBJS  = $(patsubst $(SRC)/%.c,$(OUT)/%.o,$(SRCS))

all: $(BIN)

run: $(BIN)
	$(BIN)

test: $(BIN)
	$(BIN) ~/Projects/Lexsis/Tests/Regex

$(BIN): $(OBJS)
	$(CC) $^ -o $@ $(FLGS)

$(OUT)/%.o: $(SRC)/%.c
	$(CC) -c $^ -o $@ $(FLGS)

clean:
	rm -rf $(OUT)/*

diff:
	@git status
	@git diff --stat

.PHONY: all clean diff

