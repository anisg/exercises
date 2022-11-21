/*
 * @lc app=leetcode id=77 lang=typescript
 *
 * [77] Combinations
 */

// @lc code=start
function combine(n: number, k: number): number[][] {
  return rec(1, []);

  function rec(pos: number, cur: number[]): number[][] {
    if (cur.length === k) return [cur];
    if (pos > n) {
      return [];
    }
    return [...rec(pos + 1, [...cur, pos]), ...rec(pos + 1, cur)];
  }
}
// @lc code=end
