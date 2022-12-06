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

function findEqualItems(arr: [string, string]): string[] {
  let mFirst = {};
  arr[0].split("").forEach((c) => {
    mFirst[c] = mFirst[c] ? mFirst[c] + 1 : 1;
  });
  let mSecond = {};
  arr[1].split("").forEach((c) => {
    mSecond[c] = mSecond[c] ? mSecond[c] + 1 : 1;
  });

  return Object.keys(mFirst).filter((k) => k in mSecond);
}

function findNEqualItems(...arr: string[]): string[] {
  let m = [];
  arr.forEach((s, pos) => {
    m[pos] = {};
    s.split("").forEach((c) => {
      m[pos][c] = m[pos][c] ? m[pos][c] + 1 : 1;
    });
  });
  return Object.keys(m[0]).filter((k) => m.every((m) => k in m));
}

// @ts-ignore
function main() {
  // parsing
  let sacks: [string, string][] = [];
  let s: string;
  while ((s = readline()) != null) {
    sacks.push([s.substring(0, s.length / 2), s.substring(s.length / 2)]);
  }

  // step 1
  let total = 0;
  let equalItemsMap = {};
  sacks.forEach((sack) => {
    let equalItems = findEqualItems(sack);
    if (equalItems.length != 1) {
      console.log("damn", equalItems);
    }
    equalItems.forEach((item) => {
      total += getScore(item);
      // equalItemsMap[item] = equalItemsMap[item] ? equalItemsMap[item] + 1 : 1;
    });
  });

  // compute equal items
  // Object.keys(equalItemsMap).forEach((item) => {
  //   total += getScore(item);
  // });

  console.log(total);

  // v2
  let groups: [string, string, string][] = sacks.reduce((r, sack, pos) => {
    if (pos % 3 == 0) r.push([]);
    r[r.length - 1].push(sack[0] + sack[1]);
    return r;
  }, []);

  let total2 = 0;
  groups.forEach((group) => {
    findNEqualItems(...group).forEach((item) => {
      total2 += getScore(item);
    });
  });
  console.log("v2", total2);
}

function getScore(item: string) {
  if (item.charCodeAt(0) >= "a".charCodeAt(0) && item.charCodeAt(0) <= "z".charCodeAt(0)) {
    return item.charCodeAt(0) - "a".charCodeAt(0) + 1;
  }
  return item.charCodeAt(0) - "A".charCodeAt(0) + 27;
}
