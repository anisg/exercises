/*
 * @lc app=leetcode id=198 lang=typescript
 *
 * [198] House Robber
 */

// @lc code=start
function rob(nums: number[]): number {
  if (nums.length == 1) {
    return nums[0];
  }
  if (nums.length == 2) {
    return Math.max(nums[0], nums[1]);
  }
  const n = nums.length;
  let arr = [...new Array(n)].fill(0);
  for (let i = n - 1; i >= 0; i--) {
    arr[i] = nums[i] + Math.max(0, ...arr.slice(i + 2));
  }
  return Math.max(...arr);
}
// @lc code=end
