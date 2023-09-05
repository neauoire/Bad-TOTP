#include "hotp.h"
#include "sha1.h"
#include "totp.h"

#include <stdio.h>

int
main(int argc, char **argv)
{
	if(argc == 1) {
		fprintf(stderr, "usage: totp message\n");
		return 1;
	}

	hotp_context ctx;
	ctx.secret = (const uint8_t *)argv[1];
	ctx.secretSize = sizeof(argv[1]) - 1;
	ctx.hashFn = (void *(*)(const void *, size_t))method_two;
	ctx.blockSize = 64;
	ctx.outputLength = 20;

	printf("%d\n", totp(&ctx, 6));
	return 0;
}