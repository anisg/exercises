/*
 * @lc app=leetcode id=213 lang=typescript
 *
 * [213] House Robber II
 */

// @lc code=start
function rob(nums: number[]): number {
  if (nums.length == 1) {
    return nums[0];
  }
  if (nums.length == 2) {
    return Math.max(nums[0], nums[1]);
  }
  return Math.max(
    findMaxAmount(0, nums.length - 2),
    findMaxAmount(1, nums.length - 1)
  );

  function findMaxAmount(l, r): number {
    let arr = [...new Array(r - l + 1)].fill(0);
    for (let i = r; i >= l; i--) {
      arr[i] = nums[i] + Math.max(0, ...arr.slice(i + 2));
    }
    return Math.max(...arr);
  }
}
// @lc code=end
