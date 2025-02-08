// SPDX-License-Identifier: GPL-2.0-only

#include <kunit/test.h>
#include <linux/module.h>
#include <linux/kth_element.h>

static void test_kth_element_basic(struct kunit *test)
{
	int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5};
	size_t n = ARRAY_SIZE(arr);

	KUNIT_EXPECT_EQ(test, *(int *)kth_element(arr, n, 0), 1);
	KUNIT_EXPECT_EQ(test, *(int *)kth_element(arr, n, 1), 1);
	KUNIT_EXPECT_EQ(test, *(int *)kth_element(arr, n, 2), 2);
	KUNIT_EXPECT_EQ(test, *(int *)kth_element(arr, n, 3), 3);
	KUNIT_EXPECT_EQ(test, *(int *)kth_element(arr, n, 4), 4);
	KUNIT_EXPECT_EQ(test, *(int *)kth_element(arr, n, 5), 5);
	KUNIT_EXPECT_EQ(test, *(int *)kth_element(arr, n, 6), 5);
	KUNIT_EXPECT_EQ(test, *(int *)kth_element(arr, n, 7), 6);
	KUNIT_EXPECT_EQ(test, *(int *)kth_element(arr, n, 8), 9);
}

static void test_kth_element_invalid_input(struct kunit *test)
{
	int arr[] = {1, 2, 3, 4, 5};
	size_t n = ARRAY_SIZE(arr);

	KUNIT_EXPECT_PTR_EQ(test, kth_element(NULL, n, 2), NULL);
	KUNIT_EXPECT_PTR_EQ(test, kth_element(arr, n, 5), NULL);
}

static struct kunit_case kth_element_test_cases[] = {
	KUNIT_CASE(test_kth_element_basic),
	KUNIT_CASE(test_kth_element_invalid_input),
	{}
};

static struct kunit_suite kth_element_test_suite = {
	.name = "kth_element_test",
	.test_cases = kth_element_test_cases,
};

kunit_test_suite(kth_element_test_suite);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kuan-Wei Chiu <visitorckw@gmail.com>");
MODULE_DESCRIPTION("kth_element KUnit test suite");
