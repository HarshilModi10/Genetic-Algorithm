files= readwriteppm.c main.c evolve.c fitness.c population.c crossover.c mutate.c
CFLAGS= -O2 -pg -g #-o run
LDFLAGS= -pg
CC= gcc
VOPS = --leak-check=full #--show-leak-kinds=all -v
run: 
	$(CC) $(CFLAGS) $(files) -lm
val:
	valgrind  $(VOPS) ./a.out 
time:
	time ./a.out
test:
	./a.out
clean:
	rm a.out
