all: one two

CC = g++
WORK1 = array_pointer
WORK2 = call_by_reference

one:
	$(CC) -std=c++11 $(WORK1).cc -o $(WORK1)

two:
	$(CC) -std=c++11 $(WORK2).cc -o $(WORK2)

clean:
	rm -rf $(WORK1) $(WORK2) 
