CC=gcc
CFLAGS=-g -std=c99
OFILES=browser.o site.o help_task2.o help_task3.o sort.o 
EXEC=browser

all: clean build

prerequisite:
	sudo apt-get install libncurses5-dev libncursesw5-dev

build: browser

browser: $(OFILES)
	@$(CC) -o $(EXEC) $(CFLAGS) $^ -lncurses
	@echo "Program compiled and ready to be run"
	@rm -rf *.o */*.o */*/*.o

site.o: src/code/site.c
	@$(CC) -c $^ -lncurses

help_task2.o: src/code/help_task2.c
	@$(CC) -c $^ -lncurses

help_task3.o: src/code/help_task3.c
	@$(CC) -c $^ -lncurses

sort.o: src/code/sort.c
	@$(CC) -c $^ -lncurses

browser.o: src/code/browser.c
	@$(CC) -c $^ -lncurses

task1: src/code/task1.c src/code/site.c src/code/help_task1.c
	@$(CC) -o $@ $(CFLAGS) $^ 

task2: src/code/task2.c src/code/site.c src/code/help_task2.c src/code/sort.c
	@$(CC) -o $@ $(CFLAGS) $^ 

task3: src/code/task3.c src/code/site.c src/code/help_task3.c src/code/sort.c
	@$(CC) -o $@ $(CFLAGS) $^ 

task4: src/code/task4.c src/code/site.c src/code/help_task4.c
	@$(CC) -o $@ $(CFLAGS) $^ 

clean:
	@rm -rf $(EXEC) task1 task2 task3 task4
	@rm -rf *.o */*.o */*/*.o
