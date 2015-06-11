/*
 * Copyright © 2015 Red Hat, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#if HAVE_CONFIG_H
#include "config.h"
#endif

#include "litest.h"
#include "litest-int.h"

static void
litest_protocol_a_touch_setup(void)
{
	struct litest_device *d = litest_create_device(LITEST_PROTOCOL_A_SCREEN);
	litest_set_current_device(d);
}

static struct input_event down[] = {
	{ .type = EV_ABS, .code = ABS_X, .value = LITEST_AUTO_ASSIGN },
	{ .type = EV_ABS, .code = ABS_Y, .value = LITEST_AUTO_ASSIGN },
	{ .type = EV_ABS, .code = ABS_MT_POSITION_X, .value = LITEST_AUTO_ASSIGN },
	{ .type = EV_ABS, .code = ABS_MT_POSITION_Y, .value = LITEST_AUTO_ASSIGN },
	{ .type = EV_ABS, .code = ABS_MT_TRACKING_ID, .value = LITEST_AUTO_ASSIGN },
	{ .type = EV_SYN, .code = SYN_MT_REPORT, .value = 0 },
	{ .type = EV_KEY, .code = BTN_TOUCH, .value = 1 },
	{ .type = EV_SYN, .code = SYN_REPORT, .value = 0 },
	{ .type = -1, .code = -1 },
};

static struct input_event move[] = {
	{ .type = EV_ABS, .code = ABS_X, .value = LITEST_AUTO_ASSIGN },
	{ .type = EV_ABS, .code = ABS_Y, .value = LITEST_AUTO_ASSIGN },
	{ .type = EV_ABS, .code = ABS_MT_POSITION_X, .value = LITEST_AUTO_ASSIGN },
	{ .type = EV_ABS, .code = ABS_MT_POSITION_Y, .value = LITEST_AUTO_ASSIGN },
	{ .type = EV_SYN, .code = SYN_MT_REPORT, .value = 0 },
	{ .type = EV_KEY, .code = BTN_TOUCH, .value = 1 },
	{ .type = EV_SYN, .code = SYN_REPORT, .value = 0 },
	{ .type = -1, .code = -1 },
};

static struct litest_device_interface interface = {
	.touch_down_events = down,
	.touch_move_events = move,
};

static struct input_absinfo absinfo[] = {
	{ ABS_X, 0, 32767, 0, 0, 0 },
	{ ABS_Y, 0, 32767, 0, 0, 0 },
	{ ABS_MT_POSITION_X, 0, 32767, 0, 0, 0 },
	{ ABS_MT_POSITION_Y, 0, 32767, 0, 0, 0 },
	{ ABS_MT_PRESSURE, 0, 1, 0, 0, 0 },
	{ .value = -1 },
};

static struct input_id input_id = {
	.bustype = 0x18,
	.vendor = 0xeef,
	.product = 0x20,
};

static int events[] = {
	EV_KEY, BTN_TOUCH,
	INPUT_PROP_MAX, INPUT_PROP_DIRECT,
	-1, -1,
};

struct litest_test_device litest_protocol_a_screen = {
	.type = LITEST_PROTOCOL_A_SCREEN,
	.features = LITEST_PROTOCOL_A,
	.shortname = "protocol A",
	.setup = litest_protocol_a_touch_setup,
	.interface = &interface,

	.name = "Protocol A touch screen",
	.id = &input_id,
	.events = events,
	.absinfo = absinfo,
};
