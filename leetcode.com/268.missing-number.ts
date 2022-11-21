/*
 * @lc app=leetcode id=268 lang=typescript
 *
 * [268] Missing Number
 */

// @lc code=start
function missingNumber(nums: number[]): number {
  const x = nums.sort((a, b) => a - b).findIndex((num, pos) => num != pos);

  return x != -1 ? x : nums.length;
}
// @lc code=end
