// SPDX-License-Identifier: GPL-2.0
#include <linux/kth_element.h>
#include <linux/module.h>

/* Partition function for Quick Select */
static size_t partition(int *arr, size_t left, size_t right, size_t pivot_index)
{
	size_t pivot_value, store_index;
	size_t i;

	pivot_value = arr[pivot_index];
	swap(arr[pivot_index], arr[right]);
	store_index = left;
	for (i = left; i < right; i++) {
		if (arr[i] < pivot_value) {
			swap(arr[i], arr[store_index]);
			store_index++;
		}
	}
	swap(arr[store_index], arr[right]);
	return store_index;
}

/* Find the kth smallest element */
void *kth_element(int *arr, size_t n, size_t k)
{
	size_t left = 0, right = n - 1;
	size_t pivot_index, new_pivot_index;

	if (k >= n || !arr)
		return NULL;

	while (left <= right) {
		pivot_index = left + (right - left) / 2;
		new_pivot_index = partition(arr, left, right, pivot_index);
		if (new_pivot_index == k)
			return &arr[new_pivot_index];
		else if (new_pivot_index < k)
			left = new_pivot_index + 1;
		else
			right = new_pivot_index - 1;
	}
	return NULL;
}
EXPORT_SYMBOL(kth_element);
