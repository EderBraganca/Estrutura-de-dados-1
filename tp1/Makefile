all: duelo.o principal.o
	@gcc duelo.o principal.o -o programa

duelo.o: duelo.c
	@gcc duelo.c -c

principal.o: principal.c
	@gcc principal.c -c

run:
	@./programa.exe

go: 
	@make all
	@make run

clean:
	@del *.o *.exe
	@cls