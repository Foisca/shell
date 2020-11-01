cc=gcc

_mysh: main.c utils.o ls.o touch.o cd.o pwd.o echo.o cat.o mkdir.o rm.o wc.o clear.o
	$(cc) -o $@ $^

.c.o:
	gcc -c $<

clean:
	rm -rf *.o
