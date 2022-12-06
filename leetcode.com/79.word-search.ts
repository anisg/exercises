/*
 * @lc app=leetcode id=79 lang=typescript
 *
 * [79] Word Search
 */

// @lc code=start
type Coord = { x: number; y: number };
type CoordHash = string;
function getCoordHash(coord: Coord): CoordHash {
  return `${coord.x},${coord.y}`;
}
function exist(board: string[][], word: string): boolean {
  const m = board.length;
  const n = board[0].length;

  for (let y = 0; y < board.length; y++) {
    for (let x = 0; x < board[y].length; x++) {
      if (board[y][x] === word[0]) {
        if (dfs({ x, y }, 1, { [getCoordHash({ x, y })]: true })) return true;
      }
    }
  }

  return false;

  function dfs(
    pos: Coord,
    wordIndex: number,
    visitedMap: Record<CoordHash, true>
  ): boolean {
    if (wordIndex === word.length) return true;
    return getNextCoords(pos, visitedMap, word[wordIndex]).some((coord) =>
      dfs(coord, wordIndex + 1, { ...visitedMap, [getCoordHash(coord)]: true })
    );
  }

  function getNextCoords(
    pos: Coord,
    visitedMap: Record<CoordHash, true>,
    expectedChar: string
  ): Coord[] {
    const adjacents: Coord[] = [
      { x: pos.x - 1, y: pos.y }, // left
      { x: pos.x + 1, y: pos.y }, // right
      { x: pos.x, y: pos.y - 1 }, // up
      { x: pos.x, y: pos.y + 1 }, // down
    ];

    return adjacents.filter(
      (coord) =>
        !isOutOfBound(coord) &&
        !(getCoordHash(coord) in visitedMap) &&
        board[coord.y][coord.x] === expectedChar
    );
  }

  function isOutOfBound(pos: Coord): boolean {
    return pos.x < 0 || pos.x >= n || pos.y < 0 || pos.y >= m;
  }
}
// @lc code=end
