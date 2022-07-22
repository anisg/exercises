/*
 * @lc app=leetcode id=682 lang=typescript
 *
 * [682] Baseball Game
 */

// @lc code=start
function calPoints(ops: string[]): number {
  let r: number[] = [];
  ops.forEach((op) => {
    let last = r.length - 1;
    if (op == "+") {
      r.push(r[last] + r[last - 1]);
    } else if (op == "D") {
      r.push(r[last] * 2);
    } else if (op == "C") {
      r.pop();
    } else {
      r.push(Number.parseInt(op));
    }
  });
  return r.reduce((total, cur) => total + cur, 0);
}
// @lc code=end
