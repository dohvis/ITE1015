all: one two

CC = g++ -std=c++11
WORK1 = print_people
WORK2 = my_list

one:
	$(CC) -std=c++11 $(WORK1).cc -o $(WORK1)

two:
	$(CC) -std=c++11 $(WORK2).cc -o $(WORK2)

clean:
	rm -rf $(WORK1) $(WORK2)
