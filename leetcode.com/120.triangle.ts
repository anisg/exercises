/*
 * @lc app=leetcode id=120 lang=typescript
 *
 * [120] Triangle
 */

// @lc code=start
function minimumTotal(triangle: number[][]): number {
  const computeTriangle = buildEmptyTriangle(triangle);

  for (let i = triangle.length; i >= 0; i--) {
    for (let x = 0; x < triangle[i].length; x++) {
      if (i === triangle.length) {
        computeTriangle[i][x] = triangle[i][x];
      } else {
        computeTriangle[i][x] =
          triangle[i][x] +
          Math.min(computeTriangle[i + 1][x], computeTriangle[i + 1][x + 1]);
      }
    }
  }

  return computeTriangle[0][0];

  function buildEmptyTriangle(triangle: number[][]) {
    let emptyTriangle: number[][] = [];
    for (let i = 0; i < triangle.length; i++) {
      emptyTriangle.push([]);
      for (let j = 0; j < triangle[i].length; j++) {
        emptyTriangle[i].push(0);
      }
    }
    return emptyTriangle;
  }
}
// @lc code=end
