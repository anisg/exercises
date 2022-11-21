/*
 * @lc app=leetcode id=71 lang=typescript
 *
 * [71] Simplify Path
 */

// @lc code=start
function simplifyPath(path: string): string {
  return getCanonicalPath(path);

  function getCanonicalPath(path: string): string {
    return (
      "/" +
      path
        .split("/")
        .filter((e) => !["", "."].includes(e))
        .reduce((res, cur) => {
          if (cur == "..") {
            res.pop();
          } else {
            res.push(cur);
          }
          return res;
        }, [] as string[])
        .join("/")
    );
  }
}
// @lc code=end
