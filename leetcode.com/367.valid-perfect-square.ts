/*
 * @lc app=leetcode id=367 lang=typescript
 *
 * [367] Valid Perfect Square
 */

// @lc code=start
function isPerfectSquareOld(num: number): boolean {
  return Math.floor(Math.sqrt(num)) * Math.floor(Math.sqrt(num)) == num;
}

function binarySearchFindPos<T>(
  l: number,
  r: number,
  searchedVal: T,
  getVal: (pos: number) => T
): number {
  while (l <= r) {
    let m = Math.floor((l + r) / 2);

    if (searchedVal < getVal(l) || searchedVal > getVal(r)) {
      return -1;
    } else if (searchedVal == getVal(l)) {
      return l;
    } else if (searchedVal == getVal(r)) {
      return r;
    }

    if (searchedVal == getVal(m)) {
      return m;
    } else if (searchedVal > getVal(m)) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  return -1;
}

function isPerfectSquare(num: number): boolean {
  return binarySearchFindPos(1, num, num, (pos) => pos * pos) != -1
    ? true
    : false;
}
// @lc code=end
