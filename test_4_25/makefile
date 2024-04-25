.PHONY:all
all: mybash myfile
myfile:myfile.c
	gcc -o $@ $^
mybash:myshell.c
	gcc -o $@ $^
.PHONY:clean
clean:
	rm -f mybash myfile
