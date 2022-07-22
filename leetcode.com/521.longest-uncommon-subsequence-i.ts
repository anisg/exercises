/*
 * @lc app=leetcode id=521 lang=typescript
 *
 * [521] Longest Uncommon Subsequence I
 */

// @lc code=start
function findLUSlength(a: string, b: string): number {
  if (a == b) return -1;
  return Math.max(a.length, b.length);
}
// @lc code=end
