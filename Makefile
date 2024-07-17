make:
	gcc main.c -w -lSDL2 -o game

run: game
	./game

clean:
	rm -f game
check:
		gcc check.c -w -lSDL2 -o check
		./check
