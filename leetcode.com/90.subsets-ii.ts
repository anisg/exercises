/*
 * @lc app=leetcode id=90 lang=typescript
 *
 * [90] Subsets II
 */

// @lc code=start

function backtrack<State>(
  state: State,
  getNextStates: (state: State) => State[],
  isValidState: (state: State) => boolean
): State[] {
  return [
    ...(isValidState(state) ? [state] : []),
    ...getNextStates(state).flatMap((nextState) =>
      backtrack(nextState, getNextStates, isValidState)
    ),
  ];
}

function subsetsWithDup(nums: number[]): number[][] {
  const m = {};
  nums.sort((a, b) => a - b);
  return backtrack(
    { tmp: [] as number[], pos: 0 },
    ({ tmp, pos }) =>
      [...new Array(nums.length - pos)]
        .map((_, i) => pos + i)
        .map((i) => ({ pos: i + 1, tmp: [...tmp, nums[i]] })),
    (state) => {
      const x = state.tmp.join(",");
      if (x in m) return false;
      m[x] = true;
      return true;
    }
  ).map((state) => state.tmp);
}
// @lc code=end
