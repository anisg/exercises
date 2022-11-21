/*
 * @lc app=leetcode id=93 lang=typescript
 *
 * [93] Restore IP Addresses
 */

// @lc code=start
function restoreIpAddresses(s: string): string[] {
  return getIp(0, []);
  function getIp(pos: number, tmp: string[]): string[] {
    if (tmp.length == 4 && pos >= s.length) {
      return [tmp.join(".")];
    }
    if (pos >= s.length) {
      return [];
    }
    let res: string[] = [];
    let i = pos;
    let num: string = s[i];
    while (i < s.length && isValidIpNum(num)) {
      res.push(...getIp(i + 1, [...tmp, num]));
      i += 1;
      num += s[i];
    }
    return res;
  }

  function isValidIpNum(s: string) {
    const n = Number.parseInt(s);
    return (
      ((n == 0 && s.length == 1) || !s.startsWith("0")) && n >= 0 && n <= 255
    );
  }
}
// @lc code=end
