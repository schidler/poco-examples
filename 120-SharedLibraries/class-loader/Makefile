.PHONY: all clean

all: loader plugins

clean:
	rm -f *.o loader plugins

loader: Loader.o Plugin.o
	g++ -lPocoFoundation $^ -o $@

plugins: Plugin.o HelloPlugin.o CurrentTimePlugin.o Manifest.o
	g++ -lPocoFoundation -dynamiclib $^ -o $@
