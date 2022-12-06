// ------------------------------
process.stdin.resume();
process.stdin.setEncoding("utf-8");

let inputString = "";
let lines: any = [];
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

function readline() {
  return lines[currentLine++];
}
function readintline() {
  const s = readline();
  if (!s) return [];
  return s.split(" ").map((e) => Number.parseInt(e));
}
// ------------------------------

function main() {
  let arr = [0];
  let s: string;
  let i = 0;
  while ((s = readline()) != null) {
    if (!s.length) {
      i++;
      arr.push(0);
    } else {
      arr[i] = arr[i] + Number.parseInt(s);
    }
  }
  // step 1
  console.log(Math.max(...arr));
  // step 2
  console.log(
    arr
      .sort((a, b) => b - a)
      .slice(0, 3)
      .reduce((r, x) => r + x, 0)
  );
}
