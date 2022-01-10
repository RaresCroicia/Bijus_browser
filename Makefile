build:
	gcc -o master master.c task0.c task1.c task2.c task3.c task4.c sort.c -g -lncurses
	gcc -o browser browser.c task0.c task1.c task2.c task3.c task4.c sort.c -g -lncurses

runMaster: build
	./master

runBrowser: build
	./browser
