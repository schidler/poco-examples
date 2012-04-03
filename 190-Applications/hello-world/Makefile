POCO_LIBS=-lPocoFoundation -lPocoUtil

all: hello-poco

clean:
	rm -f hello-poco

hello-poco: hello-poco.cpp
	$(CXX) $(POCO_LIBS) -o hello-poco hello-poco.cpp
