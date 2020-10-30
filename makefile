cc=g++

shell: main.c func.o ls.o touch.o
	$(cc) main.c func.o ls.o touch.o -o shell

func.o: func.c func.h
	$(cc) -c func.c 

ls.o: ls.c ls.h
	$(cc) -c ls.c

touch.o: touch.c touch.h
	$(cc) -c touch.c

clean:
	rm -rf *.o
