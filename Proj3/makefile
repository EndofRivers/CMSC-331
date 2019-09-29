PROJ = HW5-NLong2
CX = g++
CXXFLAGS = -g -ansi -Wall

OBJECTS = $(PROJ).o

Driver: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(PROJ)

Driver.o: $(PROJ).cpp
	$(CXX) $(CXXFLAGS) -c $(PROJ).cpp
clean:
	-rm -f *# *~
cleaner: clean
	-rm -f *.o
cleanest: cleaner
	-rm -f core*; rm -f $(PROJ)
run:
	./$(PROJ)
valgrind:
	valgrind ./$(PROJ)
