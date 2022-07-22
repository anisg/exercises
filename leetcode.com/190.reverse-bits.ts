/*
 * @lc app=leetcode id=190 lang=typescript
 *
 * [190] Reverse Bits
 */

// @lc code=start
function reverseBits(n: number): number {
  let res = 0;

  for (let i = 0; i <= 32; i++) {
    setbit(res, i, getbit(n, i) == 1 ? 0 : 1);
  }

  return res;

  function setbit(n: number, pos: number, val: 0 | 1) {
    n = (n & ~(1 << pos)) | (val << pos);
  }

  function getbit(n: number, pos: number) {
    return (n & (1 << pos)) != 0 ? 1 : 0;
  }
}
// @lc code=end
