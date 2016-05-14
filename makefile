# Makefile

OBJDIR = obj

CXX = clang++
CXXFLAGS = -std=c++14
TARGET = NumberTranslator

$(TARGET): $(OBJDIR)/main.o $(OBJDIR)/numbertranslator.o
	$(CXX) $(OBJDIR)/main.o $(OBJDIR)/numbertranslator.o -o $(TARGET)

$(OBJDIR)/main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o $(OBJDIR)/main.o

$(OBJDIR)/numbertranslator.o: numbertranslator.cpp numbertranslator.h
	$(CXX) $(CXXFLAGS) -c numbertranslator.cpp -o $(OBJDIR)/numbertranslator.o

.PHONY: clean
clean:
	rm $(OBJDIR)/*.o $(TARGET)
