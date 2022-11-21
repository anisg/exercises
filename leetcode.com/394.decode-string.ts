/*
 * @lc app=leetcode id=394 lang=typescript
 *
 * [394] Decode String
 */

// @lc code=start

function decodeString(s: string): string {
  return getDecoded(s, 0, 1).str;
}

function getDecoded(
  s: string,
  pos: number,
  repeat: number
): { str: string; right: number } {
  let chunks: string[] = [];

  let i = pos;
  let digits: string[] = [];
  while (i < s.length) {
    if (s[i] == "]") {
      break;
    }
    if (s[i] == "[") {
      const resp = getDecoded(s, i + 1, Number.parseInt(digits.join("")));
      digits = [];
      chunks.push(resp.str);
      i = resp.right;
    } else {
      if (
        s[i].charCodeAt(0) >= "0".charCodeAt(0) &&
        s[i].charCodeAt(0) <= "9".charCodeAt(0)
      ) {
        digits.push(s[i]);
      } else {
        chunks.push(s[i]);
      }
      i++;
    }
  }
  return { str: chunks.join("").repeat(repeat), right: i + 1 };
}
// @lc code=end
