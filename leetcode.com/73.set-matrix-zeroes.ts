/*
 * @lc app=leetcode id=73 lang=typescript
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
/**
 Do not return anything, modify matrix in-place instead.
 */
function setZeroes(matrix: number[][]): void {
  let m = matrix.length;
  let n = matrix[0].length;

  const zeros = findZeros();

  for (let [x, y] of zeros) {
    setColToZero(x);
    setRowToZero(y);
  }

  return;

  function findZeros(): [number, number][] {
    let res: [number, number][] = [];
    for (let y = 0; y < m; y++) {
      for (let x = 0; x < n; x++) {
        if (matrix[y][x] == 0) {
          res.push([x, y]);
        }
      }
    }
    return res;
  }

  function setColToZero(x) {
    for (let y = 0; y < m; y++) {
      matrix[y][x] = 0;
    }
  }

  function setRowToZero(y) {
    for (let x = 0; x < n; x++) {
      matrix[y][x] = 0;
    }
  }
}
// @lc code=end
