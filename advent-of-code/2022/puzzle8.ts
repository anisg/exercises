// ------------------------------
process.stdin.resume();
process.stdin.setEncoding("utf-8");

// @ts-ignore
let inputString = "";
// @ts-ignore
let lines: any = [];
// @ts-ignore
let currentLine = 0;

process.stdin.on("data", (inputStdin) => {
  inputString += inputStdin;
});

process.stdin.on("end", (_) => {
  lines = inputString.split("\n").map((string) => {
    return string;
  });

  main();
});

// @ts-ignore
function readline() {
  return lines[currentLine++];
}
// @ts-ignore
function readintline() {
  const s = readline();
  if (!s) return [];
  return s.split(" ").map((e) => Number.parseInt(e));
}
// ------------------------------

// @ts-ignore
function main() {
  // parsing
  let mat: number[][] = [];
  let s: string;
  while ((s = readline()) != null) {
    mat.push(s.split("").map((c) => Number.parseInt(c)));
  }

  // solve
  let count = 0;
  for (let y = 0; y < mat.length; y++) {
    for (let x = 0; x < mat[y].length; x++) {
      if (isVisible(x, y)) {
        count++;
      }
    }
  }

  console.log(count);

  let scenicScoreMax = 0;
  for (let y = 0; y < mat.length; y++) {
    for (let x = 0; x < mat[y].length; x++) {
      scenicScoreMax = Math.max(scenicScoreMax, getScenicScore(x, y));
    }
  }

  console.log(scenicScoreMax);

  function getScenicScore(x, y): number {
    return iterGetScenicScore(mat[y][x], (offset) => [x, y - offset]) + iterGetScenicScore(mat[y][x], (offset) => [x, y + offset]) + iterGetScenicScore(mat[y][x], (offset) => [x + offset, y]) + iterGetScenicScore(mat[y][x], (offset) => [x - offset, y]);
  }

  function isVisible(x, y): boolean {
    if (isEdge(x, y)) return true;
    return iterCheck(mat[y][x], (offset) => [x, y - offset]) || iterCheck(mat[y][x], (offset) => [x, y + offset]) || iterCheck(mat[y][x], (offset) => [x + offset, y]) || iterCheck(mat[y][x], (offset) => [x - offset, y]);
  }

  function iterCheck(val, fn: (offset: number) => [number, number]): boolean {
    let offset = 1;
    const r = fn(offset);
    let tmpX = r[0];
    let tmpY = r[1];
    while (!isOutOfBound(tmpX, tmpY)) {
      if (mat[tmpY][tmpX] >= val) return false;
      offset++;
      const r = fn(offset);
      tmpX = r[0];
      tmpY = r[1];
    }
    return true;
  }

  function iterGetScenicScore(val, fn: (offset: number) => [number, number]): number {
    let score = 0;
    let offset = 1;
    const r = fn(offset);
    let tmpX = r[0];
    let tmpY = r[1];
    while (!isOutOfBound(tmpX, tmpY)) {
      score += mat[tmpY][tmpX];
      if (mat[tmpY][tmpX] >= val) return score;
      offset++;
      const r = fn(offset);
      tmpX = r[0];
      tmpY = r[1];
    }
    return score;
  }

  function isEdge(x, y): boolean {
    return x == 0 || y == 0 || x == mat[0].length - 1 || y == mat.length - 1;
  }

  function isOutOfBound(x, y): boolean {
    return x < 0 || y < 0 || x >= mat[0].length || y >= mat.length;
  }
}
