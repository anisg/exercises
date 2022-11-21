/*
 * @lc app=leetcode id=398 lang=typescript
 *
 * [398] Random Pick Index
 */

// @lc code=start
class Solution {
  numsMap: Record<
    number,
    {
      indexes: number[];
    }
  > = {};
  constructor(nums: number[]) {
    for (let i = 0; i < nums.length; i++) {
      const num = nums[i];
      if (!this.numsMap[num]) {
        this.numsMap[num] = {
          indexes: [],
        };
      }
      this.numsMap[num].indexes.push(i);
    }
  }

  pick(target: number): number {
    const indexes = this.numsMap[target].indexes;
    const randomIndex = Math.floor(Math.random() * indexes.length);
    return indexes[randomIndex];
  }
}

/**
 * Your Solution object will be instantiated and called as such:
 * var obj = new Solution(nums)
 * var param_1 = obj.pick(target)
 */
// @lc code=end
