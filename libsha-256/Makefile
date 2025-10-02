#  Makefile template for Static library generation. 
# - All obj files are put under obj folder
# - Generate static library .a in lib folder
# - Run 'make dirmake' before calling 'make'
# - add '-g' in CFLAGS for debug

CC = gcc
CFLAGS = -fPIC -O2 -Wall -Wextra -c
INC = -I./
LIBS = -lm
OBJ_DIR = ./obj
OUT_DIR = ./lib

_TARGET = libSHA256.a
SRCS = sha-256.c
DEPS = sha-256.h
_OBJS = $(SRCS:.c=.o)

TARGET = $(patsubst %,$(OUT_DIR)/%,$(_TARGET)) 
OBJS = $(patsubst %,$(OBJ_DIR)/%,$(_OBJS)) 

.PHONY: all
all: ${TARGET}

$(OBJ_DIR)/%.o: %.c $(DEPS)
	$(CC) -c $(INC) $(CFLAGS) -o $@ $<
	
$(TARGET): $(OBJS)
	ar -r $@ $^
	
.PHONY: dirmake
dirmake:
	@mkdir -p $(OUT_DIR)
	@mkdir -p $(OBJ_DIR)

.PHONY: clean
clean:
	rm -f rm -f $(OBJS) $(TARGET)

