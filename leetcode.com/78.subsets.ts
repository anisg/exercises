/*
 * @lc app=leetcode id=78 lang=typescript
 *
 * [78] Subsets
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

function subsets(nums: number[]): number[][] {
  return backtrack(
    { tmp: [] as number[], pos: 0 },
    ({ tmp, pos }) =>
      [...new Array(nums.length - pos)]
        .map((_, i) => pos + i)
        .map((i) => ({ pos: i + 1, tmp: [...tmp, nums[i]] })),
    (state) => true
  ).map((state) => state.tmp);
}

// @lc code=end
