ROOT = ../../../learn/data_structure/stack

test-default: test

test:
	gcc -o test -I$(ROOT) $(ROOT)/test.c stack.c
	@echo "Run Test:\n"
	./test

clean:
	rm -rf test

.PHONY: test
