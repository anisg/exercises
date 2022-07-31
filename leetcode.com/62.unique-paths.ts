/*
 * @lc app=leetcode id=62 lang=typescript
 *
 * [62] Unique Paths
 */

// @lc code=start

function uniquePaths(m: number, n: number): number {
  const mat: number[][] = buildMatrix(m, n);

  for (let y = m - 1; y >= 0; y--) {
    for (let x = n - 1; x >= 0; x--) {
      if (y == m - 1 || x == n - 1) {
        mat[y][x] = 1;
      } else {
        mat[y][x] = mat[y][x + 1] + mat[y + 1][x];
      }
    }
  }
  return mat[0][0];

  function buildMatrix(m, n) {
    return new Array(m).fill(new Array(n).fill(0));
  }
}

// /** this solution was too slow*/
// type Pos = { x; y };

// function uniquePaths(m: number, n: number): number {
//   return solve({ x: 0, y: 0 });

//   function solve(pos: Pos): number {
//     if (isFinishPos(pos)) {
//       return 1;
//     }
//     if (isOutOfBound(pos)) {
//       return 0;
//     }
//     return (
//       solve({ x: pos.x + 1, y: pos.y }) + solve({ x: pos.x, y: pos.y + 1 })
//     );
//   }

//   function isOutOfBound(pos: Pos): boolean {
//     return pos.x < 0 || pos.x >= n || pos.y < 0 || pos.y >= m;
//   }

//   function isFinishPos(pos: Pos): boolean {
//     return pos.x == n - 1 && pos.y == m - 1;
//   }
// }
// @lc code=end
