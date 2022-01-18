build:
	gcc -o task1 task1.c site.c help_task1.c -std=c99
	gcc -o task2 task2.c site.c help_task2.c sort.c -std=c99
	gcc -o task3 task3.c site.c help_task3.c sort.c -std=c99
	gcc -o task4 task4.c site.c help_task4.c -g -lm -std=c99
	gcc -o browser browser.c site.c help_task2.c help_task3.c sort.c -g -lncurses -std=c99

clean:
	rm browser task1 task2 task3 task4
