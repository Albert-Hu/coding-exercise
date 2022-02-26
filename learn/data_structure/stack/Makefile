test-default: test-array

test-array:
	gcc -o test test.c stack_array.c
	@echo "Run Test:\n"
	./test

test-linkedlist:
	gcc -o test test.c stack_linkedlist.c
	@echo "Run Test:\n"
	./test

test-cpp:
	g++ -c stack_cpp.cpp
	gcc -lstdc++ -o test test.c stack_cpp.o
	@echo "Run Test:\n"
	./test

test-cppstl:
	g++ -c stack_cppstl.cpp
	gcc -lstdc++ -o test test.c stack_cppstl.o
	@echo "Run Test:\n"
	./test

clean:
	rm -rf test *.o

.PHONY: test
