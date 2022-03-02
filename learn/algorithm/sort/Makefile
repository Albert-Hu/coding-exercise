test-default: test-bubblesort

test-bubblesort:
	gcc -o test test.c bubblesort.c
	@echo "Run Test:\n"
	./test

clean:
	rm -rf test *.o

.PHONY: test
