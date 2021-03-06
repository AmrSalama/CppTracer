CC=g++
IDIR=include/
CFLAGS=-I $(IDIR) -lGL -lglut
OUTPUT=run
CMD=clear && $(CC) -o $(OUTPUT) $^ $(CFLAGS) && ./$(OUTPUT)

%: algorithms/%/src.cc
	$(CMD)

main: main.cc
	$(CMD)

clean:
	rm -f ./$(OUTPUT)