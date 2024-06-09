make:
	gcc main.c -w -lSDL2 -o bulltriker

run: bulltriker
	./bulltriker

clean:
	rm -f bulltriker
check:
		gcc check.c -w -lSDL2 -o check
		./check