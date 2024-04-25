.PHONY:all
all:myfile work
work:work.c
	gcc -o $@ $^
myfile:myfile.c
	gcc -o $@ $^
.PHONY:clean
clean:
	rm-r myfile work

