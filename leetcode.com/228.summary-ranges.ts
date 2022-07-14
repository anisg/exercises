/*
 * @lc app=leetcode id=228 lang=typescript
 *
 * [228] Summary Ranges
 */

// @lc code=start
function summaryRanges(nums: number[]): string[] {
  let i = 0;
  let res: string[] = [];
  while (i < nums.length) {
    let j = 0;
    while (i + j < nums.length && nums[i + j] === nums[i] + j) {
      j++;
    }
    res.push(j <= 1 ? `${nums[i]}` : `${nums[i]}->${nums[i + j - 1]}`);
    i += Math.max(j, 1);
  }
  return res;
}
// @lc code=end
