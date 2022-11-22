/*
 * @lc app=leetcode id=1828 lang=typescript
 *
 * [1828] Queries on Number of Points Inside a Circle
 */

// @lc code=start
function countPoints(points: number[][], queries: number[][]): number[] {
  return queries.map(([x, y, r]) => {
    let count = 0;
    for (let p of points) {
      if (euclidianDistance({ x, y }, { x: p[0], y: p[1] }) <= r) {
        count++;
      }
    }
    return count;
  });
}

function euclidianDistance(
  p: { x: number; y: number },
  q: { x: number; y: number }
): number {
  return Math.sqrt(Math.pow(p.x - q.x, 2) + Math.pow(p.y - q.y, 2));
}

// @lc code=end
