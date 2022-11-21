/*
 * @lc app=leetcode id=59 lang=typescript
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
type Mat = number[][];
function generateMatrix(n: number): number[][] {
  const mat: Mat = buildMatrix(n);

  fillMatrixInSpiral(mat);

  return mat;

  function buildMatrix(n): Mat {
    return [...new Array(n)].map((_) => [...new Array(n)].map((_) => 0));
  }

  function fillMatrixInSpiral(mat: Mat) {
    let dir = DIRECTION.right;
    let pos: [number, number] = [0, 0];
    let count = 1;
    while (!isOutOfBound(mat, pos)) {
      mat[pos[1]][pos[0]] = count;
      count += 1;
      if (isOutOfBound(mat, getNextPos(pos, dir))) {
        dir = getNextDirection(dir);
      }
      pos = getNextPos(pos, dir);
    }
  }

  function getNextPos([x, y], dir: DIRECTION): [number, number] {
    if (dir == DIRECTION.right) {
      x += 1;
    } else if (dir == DIRECTION.down) {
      y += 1;
    } else if (dir == DIRECTION.left) {
      x -= 1;
    } else if (dir == DIRECTION.up) {
      y -= 1;
    }
    return [x, y];
  }

  function getNextDirection(dir: DIRECTION): DIRECTION {
    return (dir + 1) % 4;
  }

  function isOutOfBound(mat: Mat, [x, y]) {
    if (x < 0 || x >= n || y < 0 || y >= n) {
      return true;
    }
    if (mat[y][x] != 0) return true;
    return false;
  }
}

enum DIRECTION {
  right = 0,
  down = 1,
  left = 2,
  up = 3,
}

// @lc code=end
