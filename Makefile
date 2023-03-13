build:
	mkdir build
	gcc -o build/ccash src/ll.c src/tsv.c src/ui.c src/main.c -lncurses
