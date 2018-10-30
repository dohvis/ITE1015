#!/bin/bash

echo "9 3 6 2 7 \n ascend \n descend \n max \n min \n 10 3 \n ascend \n quit \n" | ./sorted_array > ./sorted_array_result.txt;
cmp --silent sorted_array_result.txt correct_sorted_array_result.txt || (echo "sorted_array is wrong!" && exit 1)

echo "add 9 \n add 6 \n add 7 \n add 9 \n del 6 \n del 6 \n get 0 \n get 3 \n quit \n" | ./integer_set > ./integer_set_result.txt;
cmp --silent integer_set_result.txt correct_integer_set_result.txt || (echo "integer_set is wrong!" && exit 1)
