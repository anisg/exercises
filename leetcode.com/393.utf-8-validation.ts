/*
 * @lc app=leetcode id=393 lang=typescript
 *
 * [393] UTF-8 Validation
 */

// @lc code=start
function getUnicodeOffset(data: number[], pos: number): number | -1 {
  if (data[pos] >> 7 === 0) {
    return 1;
  } else if (data[pos] >> 5 === 0b110) {
    return checkStart(pos + 1) ? 2 : -1;
  } else if (data[pos] >> 4 === 0b1110) {
    return checkStart(pos + 1) && checkStart(pos + 2) ? 3 : -1;
  } else if (data[pos] >> 3 === 0b11110) {
    return checkStart(pos + 1) && checkStart(pos + 2) && checkStart(pos + 3)
      ? 4
      : -1;
  }

  return -1;
  function checkStart(pos) {
    return pos < data.length && data[pos] >> 6 == 0b10;
  }
}

function validUtf8(data: number[]): boolean {
  let i = 0;

  let tmp = 0;
  while (i < data.length && (tmp = getUnicodeOffset(data, i)) != -1) {
    i += tmp;
  }
  return tmp != -1;
}

// @lc code=end
