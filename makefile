# Makefile

ODIR = obj

CC = g++
TARGET = NumberTranslator

$(TARGET): $(ODIR)/main.o
	$(CC) $(ODIR)/main.o -o $(TARGET)

$(ODIR)/main.o: main.cpp
	$(CC) -c main.cpp -o $(ODIR)/main.o

.PHONY: clean
clean:
	rm $(ODIR)/*.o $(TARGET)