all: one two three

CC = g++
WORK1 = struct_person
WORK2 = array_struct_person
WORK3 = array_struct_point

one:
	$(CC) -std=c++11 $(WORK1).cc -o $(WORK1)

two:
	$(CC) -std=c++11 $(WORK2).cc -o $(WORK2)

three:
	$(CC) -std=c++11 $(WORK3).cc -o $(WORK3)
clean:
	rm -rf $(WORK1) $(WORK2) $(WORK3)

