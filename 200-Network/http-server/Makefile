SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

LDFLAGS=-lPocoNet -lPocoUtil -lPocoFoundation

.PHONY: all clean

all: simple-http-server

clean:
	rm -f $(OBJ)
	rm -f simple-http-server

simple-http-server: $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@
