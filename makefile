all: my-cat my-grep my-zip my-unzip
my-cat: my-cat.c
	gcc -o my-cat my-cat.c -Wall
my-grep: my-grep.c
	gcc -o my-grep my-grep.c -Wall
my-zip: my-zip.c
	gcc -o my-zip my-zip.c -Wall
my-unzip: my-cat.c
	gcc -o my-zip my-zip.c -Wall
