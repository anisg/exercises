/*
 * @lc app=leetcode id=2337 lang=typescript
 *
 * [2337] Move Pieces to Obtain a String
 */

// @lc code=start
function canChange(start: string, target: string): boolean {
  let n = start.length;
  let l = 0,
    r = 0;
  for (let i = 0; i < n; i++) {
    r += start[i] == "R" ? 1 : 0;
    l += target[i] == "L" ? 1 : 0;
    if (r != 0 && l != 0) return false;
    l -= start[i] == "L" ? 1 : 0;
    r -= target[i] == "R" ? 1 : 0;
    if (r < 0 || l < 0) return false;
  }
  return l == 0 && r == 0;
}
// @lc code=end
