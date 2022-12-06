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
  lines = inputString
    .trim()
    .split("\n")
    .map((string) => {
      return string.trim();
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
  let pairs: number[][][] = [];
  let s: string;
  while ((s = readline()) != null) {
    pairs.push(s.split(",").map((x) => x.split("-").map((x) => Number.parseInt(x))));
  }

  // processing
  let countFullOverlaps = 0;
  for (let pair of pairs) {
    let [a, b] = pair;
    if ((a[0] <= b[0] && a[1] >= b[1]) || (b[0] <= a[0] && b[1] >= a[1])) {
      countFullOverlaps++;
    }
  }
  console.log(countFullOverlaps);

  // v2
  let countOverlaps = 0;
  for (let pair of pairs) {
    let [a, b] = pair;
    if ((a[0] >= b[0] && a[0] <= b[1]) || (a[1] >= b[0] && a[1] <= b[1]) || (b[0] >= a[0] && b[0] <= a[1]) || (b[1] >= a[0] && b[1] <= a[1])) {
      countOverlaps++;
    }
  }
  console.log(countOverlaps);
}
