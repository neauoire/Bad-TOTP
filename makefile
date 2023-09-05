CLI_src=tests/test.c sha1.h hotp.h totp.h hmac.h

RELEASE_flags=-DNDEBUG -O2 -g0 -s -lm
DEBUG_flags=-DDEBUG -Wall -Wno-unknown-pragmas -Wpedantic -Wshadow -Wextra -Werror=implicit-int -Werror=incompatible-pointer-types -Werror=int-conversion -Wvla -g -Og -fsanitize=address -fsanitize=undefined -lm

.PHONY: run format clean

run: bin/test
	./bin/test
format:
	@ clang-format -i ${CLI_src}
clean:
	@ rm -f bin/test

bin/test: tests/test.c
	@ mkdir -p bin
	@ cc ${RELEASE_flags} tests/test.c -o bin/test
