/*
 * @lc app=leetcode id=2100 lang=typescript
 *
 * [2100] Find Good Days to Rob the Bank
 */

// @lc code=start
function goodDaysToRobBank(security: number[], time: number): number[] {
  const n = security.length;
  let prevItemsBiggerOrEqual = [...new Array(n)].fill(0);
  let nextItemsBiggerOrEqual = [...new Array(n)].fill(0);
  for (let i = 0; i < n; i++) {
    if (i > 0 && security[i - 1] >= security[i]) {
      prevItemsBiggerOrEqual[i] = prevItemsBiggerOrEqual[i - 1] + 1;
    } else {
      prevItemsBiggerOrEqual[i] = 0;
    }
  }
  for (let i = n - 1; i >= 0; i--) {
    if (i < n - 1 && security[i + 1] >= security[i]) {
      nextItemsBiggerOrEqual[i] = nextItemsBiggerOrEqual[i + 1] + 1;
    } else {
      nextItemsBiggerOrEqual[i] = 0;
    }
  }

  let res: number[] = [];
  for (let i = 0; i < n; i++) {
    if (
      prevItemsBiggerOrEqual[i] >= time &&
      nextItemsBiggerOrEqual[i] >= time
    ) {
      res.push(i);
    }
  }
  return res;
}

// @lc code=end
