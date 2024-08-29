PROG = Main
CXX = g++
CXXFLAGS = -g 
OBJS = main.o

$(PROG) : $(OBJS)
	$(CXX) -o $(PROG) $(OBJS)

main.o : vetor.h
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f $(PROG) $(OBJS)
