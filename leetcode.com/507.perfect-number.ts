/*
 * @lc app=leetcode id=507 lang=typescript
 *
 * [507] Perfect Number
 */

// @lc code=start
function checkPerfectNumber(num: number): boolean {
  const allDivisiors = getAllDivisors(num);

  return allDivisiors.reduce(reduceSum, 0) === num;

  function getAllDivisors(num: number) {
    let res: number[] = [];
    for (let i = 1; i * i <= Math.floor(num / 2); i++) {
      if (num % i == 0) {
        res.push(i);
      }
    }
    return res;
  }

  function reduceSum(total, val) {
    return total + val;
  }
}
// @lc code=end
