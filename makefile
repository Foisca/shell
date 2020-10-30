
shell: main.c func.o
	gcc main.c func.o -o shell

func.o: func.cc head.h
	gcc func.cc -o func.o 

clean:
	rm -rf *.o
