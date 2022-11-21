/*
 * @lc app=leetcode id=657 lang=typescript
 *
 * [657] Robot Return to Origin
 */

// @lc code=start
function judgeCircle(moves: string): boolean {
  let coord = {
    x: 0,
    y: 0,
  };
  for (let i = 0; i < moves.length; i++) {
    switch (moves[i]) {
      case "U":
        coord.y--;
        break;
      case "D":
        coord.y++;
        break;
      case "L":
        coord.x--;
        break;
      case "R":
        coord.x++;
        break;
    }
  }
  return coord.x == 0 && coord.y == 0;
}
// @lc code=end
