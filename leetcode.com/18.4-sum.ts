/*
 * @lc app=leetcode id=18 lang=typescript
 *
 * [18] 4Sum
 */

// @lc code=start
function fourSum(nums: number[], target: number): number[][] {
  const sum2Map: Record<number, [number, number][]> = buildSum2Map();

  let visitedKeyMap = {};

  let res = {};
  Object.entries(sum2Map).forEach(([sumKey, tuples]) => {
    const sum = Number.parseInt(sumKey);
    const otherSum = target - sum;
    if (otherSum in visitedKeyMap) return;
    visitedKeyMap[otherSum] = true;
    if (!(otherSum in sum2Map)) {
      return;
    }
    tuples.forEach(([a, b]) =>
      sum2Map[otherSum]
        .filter(([c, d]) => {
          return !(a == c || a == d || b == c || b == d);
        })
        .forEach(([c, d]) => {
          res[
            [nums[a], nums[b], nums[c], nums[d]].sort((a, b) => a - b).join(",")
          ] = true;
        })
    );
  });

  return Object.keys(res).map((k) =>
    k.split(",").map((e) => Number.parseInt(e))
  );

  function buildSum2Map() {
    let sum2Map = {};
    for (let i = 0; i < nums.length; i++) {
      for (let j = i + 1; j < nums.length; j++) {
        let sum = nums[i] + nums[j];
        if (sum in sum2Map) {
          sum2Map[sum].push([i, j]);
        } else {
          sum2Map[sum] = [[i, j]];
        }
      }
    }
    return sum2Map;
  }
}
// @lc code=end
