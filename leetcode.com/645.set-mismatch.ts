/*
 * @lc app=leetcode id=645 lang=typescript
 *
 * [645] Set Mismatch
 */

// @lc code=start
function findErrorNumsV1(nums: number[]): number[] {
  return [findDuplicate(nums), findMissingNum(nums)];

  function findMissingNum(nums: number[]): number {
    let prev = 0;
    const sorted = [...nums].sort((a, b) => a - b);

    if (sorted[0] != 1) return 1;
    if (sorted[nums.length - 1] != nums.length) return nums.length;

    const sortedWithoutDuplicate = sorted.filter(
      (_, pos, arr) => pos == 0 || arr[pos - 1] != arr[pos]
    );
    return (
      sortedWithoutDuplicate.findIndex((a, pos) => {
        if (a - 1 != prev) {
          return true;
        }
        prev = a;
        return false;
      }) + 1
    );
  }

  function findDuplicate(nums: number[]): number {
    let numsMap = {};
    return (
      nums.find((num) => {
        if (num in numsMap) return true;
        numsMap[num] = true;
        return false;
      }) || 0
    );
  }
}
function findErrorNums(nums: number[]): number[] {}

// @lc code=end
