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
  let entries: {
    command: string;
    responses: string[];
  }[] = [];
  while ((s = readline()) != null) {
    if (s.startsWith("$ ")) {
      entries.push({
        command: s.trim(),
        responses: [],
      });
    } else {
      entries[entries.length - 1].responses.push(s.trim());
    }
  }

  let dirMap: Record<
    string,
    {
      dirs: string[];
      files: { file: string; size: number }[];
      size: number;
      recSize: number;
    }
  > = {};
  let pos = "/";
  dirMap[pos] = {
    dirs: [],
    files: [],
    size: 0,
    recSize: 0,
  };
  for (let entry of entries) {
    let [$, cmd, param] = entry.command.split(" ");
    if (cmd == "cd") {
      if (param == "/") {
        pos = "/";
      } else if (param == "..") {
        pos = pos.slice(0, pos.lastIndexOf("/"));
        if (pos == "") pos = "/";
      } else {
        const childPath = `${pos != "/" ? pos : ""}/${param}`;
        pos = childPath;
        dirMap[pos] = {
          dirs: [],
          files: [],
          size: 0,
          recSize: 0,
        };
      }
    } else {
      for (let response of entry.responses) {
        if (response.startsWith("dir ")) {
          const childPath = `${pos != "/" ? pos : ""}/${response.slice(4)}`;
          dirMap[pos].dirs.push(childPath);
        } else {
          let [size, file] = response.split(" ");
          if (!size) {
            continue;
          }
          dirMap[pos].files.push({ file, size: Number.parseInt(size) });
          dirMap[pos].size += Number.parseInt(size);
        }
      }
    }
  }

  dfs("/");

  function dfs(path: string) {
    let dir = dirMap[path];
    dir.recSize = dir.size;
    for (let dirName of dir.dirs) {
      dfs(dirName);
      dir.recSize += dirMap[dirName].recSize;
    }
  }

  let count = 0;
  for (let o of Object.keys(dirMap).sort()) {
    if (dirMap[o].recSize < 1000000) {
      count += dirMap[o].recSize;
    }
  }

  console.log(dirMap["/"]);
}
