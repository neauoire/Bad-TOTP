/*
 * RFC 6238
 */
#ifndef TOTP_H
#define TOTP_H

#include "hotp.h"
#include <time.h>

#define T0 0
#define X 30 // time step

uint32_t
totp(hotp_context *ctx, uint8_t digits)
{
	time_t now = time(NULL);
	ctx->counter = (now - T0) / X;

	return hotp(ctx, digits);
}

#endif
