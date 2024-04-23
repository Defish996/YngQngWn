.PHONY:all
all:mytest process
mytest:mytest.cc
	g++ -o $@ $^ 
process:process.c
	gcc -o $@ $^ -std=c99
.PHONY:clean
clean:
	rm -f mytest process
