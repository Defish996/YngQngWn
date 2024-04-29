dy-lib=libmymath.so

$(dy-lib):Add.o Div.o Mul.o Sub.o
	gcc -shared -o $@ $^
%o:%c
	gcc -fPIC -c $<
.PHONY:output
output:
	mkdir -p mymath_lib/include
	mkdir -p mymath_lib/lib
	cp -f *.h mymath_lib/include
	cp -f *.so mymath_lib/lib 


.PHONY:clean
clean:
	rm -rf *.o *.so mymath_lib  
