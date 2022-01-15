build:
	gcc -o master master.c site.c help_task1.c help_task2.c help_task3.c help_task4.c sort.c -g -lncurses
	gcc -o browser browser.c site.c help_task1.c help_task2.c help_task3.c help_task4.c sort.c -g -lncurses
	gcc -o task1 task1.c site.c help_task1.c help_task2.c help_task3.c help_task4.c sort.c -g -lncurses
	gcc -o task2 task2.c site.c help_task1.c help_task2.c help_task3.c help_task4.c sort.c -g -lncurses
	gcc -o task3 task3.c site.c help_task1.c help_task2.c help_task3.c help_task4.c sort.c -g -lncurses
	gcc -o task4 task4.c site.c help_task1.c help_task2.c help_task3.c help_task4.c sort.c -g -lncurses

runMaster: build
	./master

runBrowser: build
	./browser
