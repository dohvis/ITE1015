all: one two three

CC = g++
WORK1 = struct_person
WORK2 = array_struct_person
WORK3 = array_struct_point

one:
	$(CC) $(WORK1).cc -o $(WORK1)

two:
	$(CC) $(WORK2).cc -o $(WORK2)

three:
	$(CC) $(WORK3).cc -o $(WORK3)
clean:
	rm -rf $(WORK1) $(WORK2) $(WORK3)

