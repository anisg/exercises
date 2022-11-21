/*
 * @lc app=leetcode id=12 lang=typescript
 *
 * [12] Integer to Roman
 */

// @lc code=start
function intToRoman(num: number): string {
  const dic = [
    {
      single: "I",
      five: "V",
      ten: "X",
    },
    {
      single: "X",
      five: "L",
      ten: "C",
    },
    {
      single: "C",
      five: "D",
      ten: "M",
    },
    {
      single: "M",
      five: "",
      ten: "",
    },
  ];
  let n = 0;
  let res: string[] = [];
  let tmp = num;
  while (tmp) {
    let remainder = tmp % 10;
    if (remainder) {
      if (remainder <= 3) {
        res.push(dic[n].single.repeat(remainder));
      } else if (remainder == 4) {
        res.push(dic[n].single + dic[n].five);
      } else if (remainder == 5) {
        res.push(dic[n].five);
      } else if (remainder <= 8) {
        res.push(dic[n].five + dic[n].single.repeat(remainder - 5));
      } else if (remainder == 9) {
        res.push(dic[n].single + dic[n].ten);
      }
    }
    tmp = Math.floor(tmp / 10);
    n += 1;
  }
  return res.reverse().join("");
}

// @lc code=end
