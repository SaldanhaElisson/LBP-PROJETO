# Name of the project
PROJ_NAME=main
 
# .c files
C_SOURCE=$(wildcard ./pgm/src/*.c)
 
# .h files
H_SOURCE=$(wildcard ./pgm/inc/*.h)
 
# Object files
OBJ=$(subst .c,.o,$(subst src,objects,$(C_SOURCE)))
 
# Compiler
CC=gcc
 
# Flags for compiler
CC_FLAGS=-c         \
         -W         \
         -Wall      \
         -pedantic
 
#
# Compilation and linking
#
all: $(PROJ_NAME)
 
$(PROJ_NAME): $(OBJ) 
	@ echo 'Building binary using GCC linker: $@'
	$(CC) $^ -o $@ -lm
	@ echo 'Finished building binary: $@'
	@ echo ' '
 
./pgm/objects/%.o: ./pgm/src/%.c 
	@ echo 'Building target using GCC compiler: $<'
	$(CC) $<  $(CC_FLAGS)  -o $@ -I./pgm/inc -lm
	@ echo ' '
 
# ./pgm/objects/main.o: ./pgm/src/main.c $(H_SOURCE)
# 	@ echo 'Building target using GCC compiler: $<'
# 	$(CC) $< $(CC_FLAGS) -I./pgm/inc -o $@
# 	@ echo ' '
 
 
clean:
	@ $(RM) ./pgm/objects/*.o $(PROJ_NAME) *~
	@ rmdir objects
 
.PHONY: all clean