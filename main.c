#include "sha1.h"
#include "hotp.h"
#include "totp.h"

#include <stdio.h>

int main(int argc, char **argv) {
  const char secret[] = "a very secret key!!!";

  hotp_context ctx;
  ctx.secret = (const uint8_t*) secret;
  ctx.secretSize = sizeof(secret) - 1;
  ctx.hashFn = (void* (*) (const void*, size_t)) method_two;
  ctx.blockSize = 64;
  ctx.outputLength = 20;

  printf("%d\n", totp(&ctx, 6));
  return 0;
}