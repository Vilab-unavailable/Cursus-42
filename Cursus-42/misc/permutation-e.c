#include <stdio.h>

/*
 * Échange deux éléments
 */
void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/*
 * Affiche le tableau
 */
void printArray(int* nums, int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    printf("]\n");
}

/*
 * Backtracking avec échange en place
 */
void permute(int* nums, int start, int size) {
    if (start == size) {
        printArray(nums, size);
        return;
    }

    for (int i = start; i < size; i++) {
        swap(&nums[start], &nums[i]);
        permute(nums, start + 1, size);
        swap(&nums[start], &nums[i]); // backtracking
    }
}

int main(void) {
    int nums[] = {1, 2, 3};
    int size = sizeof(nums) / sizeof(nums[0]);

    permute(nums, 0, size);
    return 0;
}
