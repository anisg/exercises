/*
 * @lc app=leetcode id=57 lang=typescript
 *
 * [57] Insert Interval
 */

// @lc code=start
type Resp = {
  leftPos: number;
  mergeLeft: boolean;
  rightPos: number;
  mergeRight: boolean;
};
function insert(intervals: number[][], newInterval: number[]): number[][] {
  const resp = findPosToInsert();

  function findPosToInsert(): Resp {
    const resp: Resp = {
      leftPos: -1,
      mergeLeft: false,
      rightPos: -1,
      mergeRight: false,
    };
    for (let i = 0; i < intervals.length; i++){
      if (newInterval[i][0] >= intervals[i][0]){
        resp.leftPos = i;
        if (areOverlapping(newInterval,intervals[i])){
          resp.mergeLeft = true;
        }
        break;
      }
    }
    if (resp.leftPos == -1){
      resp.leftPos = intervals.length;
    }
    for (let i = intervals.length-1; i++){

    }

    return resp;
  }

  function areOverlapping(intA: number[], intB: number[]): boolean {
    const [x, y] = [intA, intB].sort((a, b) => a[0] - b[0]);
    return x[1] >= y[0];
  }
}
// @lc code=end
