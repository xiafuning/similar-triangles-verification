#Makefile for similar triangles verification
#http://man7.org/linux/man-pages/man1/g++.1.html

IDIR_DEP     = 
LIBDIR       = 

CC = g++
CFLAGS = -g -Wall -std=c++11 -lpthread
SRC = similar-triangles-verification
OUTPUT = out

$(OUTPUT) : $(OUTPUT).o
	$(CC) $^ -o $@ $(CFLAGS)
	@echo "Linking complete!"

$(OUTPUT).o : $(OUTPUT).s
	$(CC) -c $^ -o $@ $(CFLAGS)
	@echo "Assembly complete!"

$(OUTPUT).s : $(OUTPUT).i
	$(CC) -S $^ -o $@ $(CFLAGS)
	@echo "Compilation complete!"

$(OUTPUT).i : $(SRC).cpp
	$(CC) -E $^ -o $@ $(CFLAGS)
	@echo "Pre-processing complete!"

clean:
	rm -fr $(OUTPUT)*
