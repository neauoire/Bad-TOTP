CLI_src=sha1.h hotp.h totp.h hmac.h

RELEASE_flags=-DNDEBUG -O2 -g0 -s -lm
DEBUG_flags=-DDEBUG -Wall -Wno-unknown-pragmas -Wpedantic -Wshadow -Wextra -Werror=implicit-int -Werror=incompatible-pointer-types -Werror=int-conversion -Wvla -g -Og -fsanitize=address -fsanitize=undefined -lm

.PHONY: run format clean

run: bin/main bin/test
	@ ./bin/test
	@ ./bin/totp
format:
	@ clang-format -i ${CLI_src} main.c tests/test.c
clean:
	@ rm -f bin/test

bin/main: main.c
	@ mkdir -p bin
	@ cc main.c ${CLI_src} ${RELEASE_flags} -o bin/totp

bin/test: tests/test.c
	@ mkdir -p bin
	@ cc tests/test.c ${CLI_src} ${RELEASE_flags} -o bin/test
