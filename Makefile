flags := -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install

install: objects
	@make -C ./libmx
	@clang $(flags) -o pathfinder obj/*.o libmx/libmx.a

objects:
	@mkdir -p obj
	@clang $(flags) -c src/*.c
	@mv *.o obj/

uninstall: clean
	@rm -rf pathfinder
	@rm -rfd obj/
	@rm -rf libmx.a
	@make uninstall -C ./libmx

clean:
	@rm -rf obj

reinstall:
	@make uninstall
	@make