/*
 * @lc app=leetcode id=278 lang=typescript
 *
 * [278] First Bad Version
 */

// @lc code=start
/**
 * The knows API is defined in the parent class Relation.
 * isBadVersion(version: number): boolean {
 *     ...
 * };
 */

//@ts-ignore
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

var solution = function (isBadVersion: any) {
  return function (n: number): number {
    return binarySearchFindPos(1, n, 0, (pos) => {
      if (!isBadVersion(pos)) {
        return -1;
      }
      if (pos == 1 || !isBadVersion(pos - 1)) {
        return 0;
      }
      return 1;
    });
  };
};
// @lc code=end
