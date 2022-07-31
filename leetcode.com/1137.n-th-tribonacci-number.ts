/*
 * @lc app=leetcode id=1137 lang=typescript
 *
 * [1137] N-th Tribonacci Number
 */

// @lc code=start
function tribonacci(n: number): number {
  const r = [0, 1, 1];
  for (let i = 3; i <= n; i++) {
    r.push(r[i - 3] + r[i - 2] + r[i - 1]);
  }
  return r[n];
}
// @lc code=end
