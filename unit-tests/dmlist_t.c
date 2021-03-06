/*
 * Copyright (C) 2015 Red Hat, Inc. All rights reserved.
 *
 * This file is part of LVM2.
 *
 * This copyrighted material is made available to anyone wishing to use,
 * modify, copy, or redistribute it subject to the terms and conditions
 * of the GNU General Public License v.2.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include "units.h"

#include "base/memory/array-size.h"

#include <stdio.h>
#include <stdlib.h>

static void test_dmlist_splice(void *fixture)
{
	unsigned i;
	struct list a[10];
	struct list list1;
	struct list list2;

	list_init(&list1);
	list_init(&list2);

	for (i = 0; i < ARRAY_SIZE(a); i++)
		list_add(&list1, &a[i]);

	list_splice(&list2, &list1);
	T_ASSERT(list_size(&list1) == 0);
	T_ASSERT(list_size(&list2) == 10);
}

#define T(path, desc, fn) register_test(ts, "/base/data-struct/list/" path, desc, fn)

void list_tests(struct list *all_tests)
{
	struct test_suite *ts = test_suite_create(NULL, NULL);
	if (!ts) {
		fprintf(stderr, "out of memory\n");
		exit(1);
	}

	T("splice", "joining lists together", test_dmlist_splice);

	list_add(all_tests, &ts->list);
}
