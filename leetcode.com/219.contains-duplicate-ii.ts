/*
 * @lc app=leetcode id=219 lang=typescript
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
function containsNearbyDuplicate(nums: number[], k: number): boolean {
  const m = {};
  return nums.some((num, pos) => {
    if (num in m && Math.abs(m[num] - pos) <= k) return true;
    m[num] = pos;
    return false;
  });
}
// @lc code=end
