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
  let lines: string[][] = [];
  let moves: { count: number; from: number; to: number }[] = [];
  let s: string;
  while ((s = readline()) != null) {
    // parse stacks
    if (s.length == 0) {
      break;
    }
    let line: string[] = [];
    for (let i = 0; i < s.length; i += 4) {
      line.push(
        s
          .substring(i, i + 3)
          .replace("[", "")
          .replace("]", "")
          .trim()
      );
    }
    lines.push(line);
  }
  lines.pop();
  let n = lines.length;
  let stacks = [...new Array(lines[0].length)].map((_, pos) => {
    let stack: string[] = [];
    for (let i = n - 1; i >= 0; i--) {
      if (lines[i][pos] != "") {
        stack.push(lines[i][pos]);
      }
    }
    return stack;
  });

  while ((s = readline()) != null) {
    const r = /move (\d+) from (\d+) to (\d+)/.exec(s);
    if (!r) {
      break;
    }
    // parse moves
    moves.push({
      count: Number.parseInt(r[1]),
      from: Number.parseInt(r[2]),
      to: Number.parseInt(r[3]),
    });
  }

  //perform moves
  for (let move of moves) {
    let from = stacks[move.from - 1];
    let to = stacks[move.to - 1];
    let count = move.count;
    let top = from.slice(from.length - count);
    from.splice(from.length - count, count);
    to.push(...top);
  }
  let res = [];
  for (let stack of stacks) {
    res.push(stack[stack.length - 1] ?? " ");
  }
  console.log(res.join(""));
}
