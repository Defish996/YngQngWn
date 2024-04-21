.PHONY:all
all:test testl process
test:test.c
	gcc -o $@ $^
process:process.c
	gcc -o $@ $^
testl:testl.c
	gcc -o $@ $^
.PHONY:clean
clean:
	rm -f testl test process
