/*
 * @lc app=leetcode id=39 lang=typescript
 *
 * [39] Combination Sum
 */

// @lc code=start
function combinationSum(candidates: number[], target: number): number[][] {
  let n = candidates.length;

  return bruteForceRec([], 0, 0);
  function bruteForceRec(cur: number[], sum: number, pos: number): number[][] {
    if (sum == target) return [cur];
    if (pos >= n || sum > target) return [];
    return [
      ...bruteForceRec([...cur, candidates[pos]], sum + candidates[pos], pos),
      ...bruteForceRec(cur, sum, pos + 1),
    ];
  }
}
// @lc code=end
