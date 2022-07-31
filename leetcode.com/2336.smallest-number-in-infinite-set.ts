/*
 * @lc app=leetcode id=2336 lang=typescript
 *
 * [2336] Smallest Number in Infinite Set
 */

// @lc code=start
class SmallestInfiniteSet {
  reintegratedMap: Record<number, boolean> = {};
  reintegratedRevArr: number[] = [];
  smallest = 1;
  constructor() {}

  popSmallest(): number {
    if (this.reintegratedRevArr.length) {
      const last = this.reintegratedRevArr.pop();
      delete this.reintegratedMap[last as number];
      return last as number;
    }
    return this.smallest++;
  }

  addBack(num: number): void {
    if (num in this.reintegratedMap || num >= this.smallest) {
      return;
    }
    this.reintegratedMap[num] = true;
    this.reintegratedRevArr.push(num);
    this.reintegratedRevArr.sort((a, b) => b - a);
  }
}

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * var obj = new SmallestInfiniteSet()
 * var param_1 = obj.popSmallest()
 * obj.addBack(num)
 */
// @lc code=end
