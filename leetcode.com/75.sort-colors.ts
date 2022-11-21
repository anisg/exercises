/*
 * @lc app=leetcode id=75 lang=typescript
 *
 * [75] Sort Colors
 */

// @lc code=start
/**
 Do not return anything, modify nums in-place instead.
 */
function sortColors(nums: number[]): void {
  const r = nums.reduce(
    (res, num) => {
      res[num]++;
      return res;
    },
    [0, 0, 0]
  );

  r[1] += r[0];
  r[2] += r[1];

  for (let i = 0; i < nums.length; i++) {
    if (i < r[0]) {
      nums[i] = 0;
    } else if (i < r[1]) {
      nums[i] = 1;
    } else {
      nums[i] = 2;
    }
  }
}

// @lc code=end
