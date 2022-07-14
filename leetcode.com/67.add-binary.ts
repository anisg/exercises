/*
 * @lc app=leetcode id=67 lang=typescript
 *
 * [67] Add Binary
 */

// @lc code=start
function addBinary(a: string, b: string): string {
  const aArr = a.split("").reverse();
  const bArr = b.split("").reverse();
  const resultArr: number[] = [];
  let carry = 0;
  for (let i = 0; i < aArr.length || i < bArr.length; i++) {
    const aNum = aArr[i] ? parseInt(aArr[i]) : 0;
    const bNum = bArr[i] ? parseInt(bArr[i]) : 0;

    const res = (aNum + bNum + carry) % 2;
    resultArr.push(res);
    carry = Math.floor((aNum + bNum + carry) / 2);
  }
  if (carry) {
    resultArr.push(carry);
  }
  return resultArr.reverse().join("");
}

// @lc code=end
