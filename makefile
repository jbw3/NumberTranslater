# Makefile

ODIR = obj

CC = g++
TARGET = NumberTranslator

$(TARGET): $(ODIR)/main.o $(ODIR)/numbertranslator.o
	$(CC) $(ODIR)/main.o $(ODIR)/numbertranslator.o -o $(TARGET)

$(ODIR)/main.o: main.cpp
	$(CC) -c main.cpp -o $(ODIR)/main.o

$(ODIR)/numbertranslator.o: numbertranslator.cpp numbertranslator.h
	$(CC) -c numbertranslator.cpp -o $(ODIR)/numbertranslator.o

.PHONY: clean
clean:
	rm $(ODIR)/*.o $(TARGET)