/*
 * @lc app=leetcode id=263 lang=typescript
 *
 * [263] Ugly Number
 */

// @lc code=start
function isUgly(n: number): boolean {
  let res = divideBy(divideBy(divideBy(n, 2), 3), 5);

  return res == 1;

  function divideBy(nb, by): number {
    let res = nb;
    while (res > 1) {
      if (res % by != 0) {
        break;
      }
      res = res / by;
    }
    return res;
  }
}
// @lc code=end
