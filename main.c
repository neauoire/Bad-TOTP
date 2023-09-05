#include "hotp.h"
#include "sha1.h"
#include "totp.h"

#include <stdio.h>

int
generate(char *s)
{
	hotp_context ctx;
	ctx.secret = (const uint8_t *)s;
	ctx.secretSize = sizeof(s) - 1;
	ctx.hashFn = (void *(*)(const void *, size_t))method_two;
	ctx.blockSize = 64;
	ctx.outputLength = 20;
	return totp(&ctx, 6);
}

int
main(int argc, char **argv)
{
	if(argc == 1) {
		fprintf(stderr, "usage: totp message\n");
		return 1;
	}
	printf("%d\n", generate(argv[1]));
	return 0;
}