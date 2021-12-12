# This is the default target, which will be built when 
# you invoke make
.PHONY: all
all: run

# This rule tells make how to build main from main.c
run: main
	./main
	

# This rule tells make how to build main from main.c
main: main.c deps.h
	clang -D DESKTOP_DEBUG_MODE -o main main.c

