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

function readline() {
  return lines[currentLine++];
}
function readintline() {
  const s = readline();
  if (!s) return [];
  return s.split(" ").map((e) => Number.parseInt(e));
}
// ------------------------------

type Action = "rock" | "paper" | "scissors";

function getMatchScore(a: Action, b: Action) {
  if (beats(a, b)) return 0;
  if (a === b) return 3;
  return 6;

  function beats(x: Action, y: Action) {
    return (x === "rock" && y === "scissors") || (x === "paper" && y === "rock") || (x === "scissors" && y === "paper");
  }
}

function main() {
  // parsing
  let matches: [Action, Action][] = [];
  let s: string;
  let m = {
    A: "rock",
    B: "paper",
    C: "scissors",
    X: "rock",
    Y: "paper",
    Z: "scissors",
  };
  while ((s = readline()) != null) {
    matches.push(s.split(" ").map((x) => m[x]) as [Action, Action]);
  }

  // step 1
  let sum = 0;
  let scoreMap = {
    rock: 1,
    paper: 2,
    scissors: 3,
  };
  for (let match of matches) {
    sum += getMatchScore(match[0], match[1]) + scoreMap[match[1]];
  }
  console.log(sum);
  // step 2

  sum = 0;
  let scoreV2Map = {
    rock: 0,
    paper: 3,
    scissors: 6,
  };
  for (let match of matches) {
    let expect = scoreV2Map[match[1]];
    for (let action of ["rock", "paper", "scissors"]) {
      let x = getMatchScore(match[0], action as Action);
      if (x == expect) {
        sum += scoreMap[action] + expect;
        break;
      }
    }
  }
  console.log("v2>", sum);
}
