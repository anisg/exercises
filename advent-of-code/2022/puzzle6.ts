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
  let s: string;
  s = readline();

  // v1
  console.log(getFirstUniqueSubstringKLength(s, 4));

  // v2
  console.log(getFirstUniqueSubstringKLength(s, 14));
}

function getFirstUniqueSubstringKLength(s: string, k: number): number | -1 {
  const freqMap = {};
  const n = s.length;
  for (let i = 0; i < k; i++) {
    freqMap[s[i]] = (freqMap[s[i]] || 0) + 1;
  }
  for (let i = k; i <= n; i += 1) {
    if (countNoDup(freqMap)) {
      return i;
    }
    if (i < n) {
      // remove
      freqMap[s[i - k]] -= 1;
      if (freqMap[s[i - k]] === 0) {
        delete freqMap[s[i - k]];
      }
      // add
      freqMap[s[i]] = (freqMap[s[i]] || 0) + 1;
    }
  }
  return -1;
}

function countNoDup(m: Record<string, number>) {
  return Object.keys(m).every((k) => m[k] === 1);
}
