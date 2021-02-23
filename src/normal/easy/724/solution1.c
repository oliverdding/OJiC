//
// Created by olive on 2/20/2021.
//

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int
pivotIndex(int *nums, int numsSize) {
    if (numsSize == 0) {
        return -1;
    }
    int leftSum[numsSize + 2], rightSum[numsSize + 2]; // To solve the border
    leftSum[0] = 0;
    leftSum[numsSize + 1] = 0;
    rightSum[0] = 0;
    rightSum[numsSize + 1] = 0;
    for (int i = 1; i <= numsSize; ++i) {
        leftSum[i] = leftSum[i - 1] + nums[i - 1];
    }
    for (int i = numsSize; i >= 1; --i) {
        rightSum[i] = rightSum[i + 1] + nums[i - 1];
    }
    for (int i = 1; i <= numsSize; ++i) {
        if (leftSum[i - 1] == rightSum[i + 1]) {
            return i - 1;
        }
    }
    return -1;
}

int
main(void) {
    printf("Test for 724\n");
    int nums1[6] = {1, 7, 3, 6, 5, 6};
    assert(3 == pivotIndex(nums1, 6));
    int nums2[3] = {1, 2, 3};
    assert(-1 == pivotIndex(nums2, 3));
    return EXIT_SUCCESS;
}
