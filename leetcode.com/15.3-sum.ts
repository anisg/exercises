/*
 * @lc app=leetcode id=15 lang=typescript
 *
 * [15] 3Sum
 */

// @lc code=start
function threeSum(nums: number[]): number[][] {
  let freqMap: Record<number, number[]> = buildFreqMap(nums);

  let foundMap = {};

  for (let i = 0; i < nums.length; i++) {
    for (let j = i + 1; j < nums.length; j++) {
      const x = getLastPos([i, j], freqMap);
      if (x !== -1) {
        foundMap[
          [i, j, x]
            .map((e) => nums[e])
            .sort((a, b) => a - b)
            .join(",")
        ] = true;
      }
    }
  }

  return Object.keys(foundMap).map((k) => k.split(",").map((e) => parseInt(e)));

  function getLastPos(
    cur: [number, number],
    freqMap: Record<number, number[]>
  ): number | -1 {
    const searched = (nums[cur[0]] + nums[cur[1]]) * -1;
    if (`${searched}` in freqMap) {
      let posIndex = freqMap[`${searched}`].findIndex((curPos) => {
        if (searched === nums[cur[0]] && cur[0] === curPos) return false;
        if (searched === nums[cur[1]] && cur[1] === curPos) return false;
        return true;
      });
      if (posIndex == -1) return -1;
      return freqMap[`${searched}`][posIndex];
    }
    return -1;
  }
  function buildFreqMap(nums: number[]): Record<number, number[]> {
    const freqMap: Record<number, number[]> = {};
    nums.forEach((num, pos) => {
      if (!(num in freqMap)) {
        freqMap[`${num}`] = [pos];
      } else {
        freqMap[`${num}`].push(pos);
      }
    });
    return freqMap;
  }
}
// @lc code=end
