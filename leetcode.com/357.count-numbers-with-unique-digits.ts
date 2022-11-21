/*
 * @lc app=leetcode id=357 lang=typescript
 *
 * [357] Count Numbers with Unique Digits
 */

// @lc code=start
function countNumbersWithUniqueDigits(n: number): number {
  let count = 0;
  for (let i = 0; i < 10 ** n; i++) {
    if (isUnique(i)) {
      count++;
    }
  }
  return count;

  function isUnique(i) {
    let m = {};
    const dup = `${i}`.split("").find((c) => {
      if (c in m) {
        return true;
      }
      m[c] = true;
      return false;
    });
    return !dup;
  }
}
// @lc code=end
