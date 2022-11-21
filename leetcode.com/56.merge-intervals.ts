/*
 * @lc app=leetcode id=56 lang=typescript
 *
 * [56] Merge Intervals
 */

// @lc code=start
function merge(intervals: number[][]): number[][] {
  const sortedAscIntervals = [...intervals].sort((a, b) => a[0] - b[0]);

  let i = 0;
  while (i < sortedAscIntervals.length) {
    if (areOverlapping(sortedAscIntervals[i], sortedAscIntervals[i + 1])) {
      mergeIntervals(sortedAscIntervals, i, i + 1);
    } else {
      i++;
    }
  }

  return sortedAscIntervals;

  function areOverlapping(intA: number[], intB: number[]): boolean {
    if (!intA || !intB) return false;
    return intA[1] >= intB[0];
  }

  function mergeIntervals(ints: number[][], i, j) {
    ints.splice(i, 2, [ints[i][0], Math.max(ints[i][1], ints[j][1])]);
  }
}
// @lc code=end
