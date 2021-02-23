//
// Created by olive on 2/20/2021.
//

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/**
 * 二分查找
 */
int
searchInsert(int* nums, int numsSize, int target){
    int head = 0, tail = numsSize - 1;
    while(head <= tail) {
        int mid = head + (tail - head) / 2;
        if(nums[mid] == target){
            return mid;
        } else if (nums[mid] > target) {
            tail = mid - 1;
        } else {
            head = mid + 1;
        }
    }
    return head;
}

int
main(void) {
    printf("Test for 35\n");
    int nums1[4] = {1, 3, 5, 6};
    assert(2 == searchInsert(nums1, 4, 5));
    int nums2[4] = {1,3,5,6};
    assert(1 == searchInsert(nums2, 4, 2));
    int nums3[4] = {1,3,5,6};
    assert(4 == searchInsert(nums3, 4, 7));
    int nums4[4] = {1,3,5,6};
    assert(0 == searchInsert(nums4, 4, 0));
    return EXIT_SUCCESS;
}
