/*
 * @lc app=leetcode id=5 lang=typescript
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
function longestPalindrome(s: string): string {
  function isPalindrome(l, r) {
    for (let c = 0; l + c <= Math.floor((l + r) / 2); c++) {
      if (s[l + c] != s[r - c]) return false;
    }
    return true;
  }
  let r = s[0];
  for (let i = 0; i < s.length; i++) {
    for (let j = i + 1; j < s.length; j++) {
      if (isPalindrome(i, j)) {
        if (j - i + 2 > r.length) {
          r = s.substring(i, j + 1);
        }
      }
    }
  }
  return r;
}
// @lc code=end
