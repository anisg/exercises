/*
 * @lc app=leetcode id=46 lang=typescript
 *
 * [46] Permutations
 */

// @lc code=start
function backtrack<State>(
  state: State,
  getNextStates: (state: State) => State[],
  isValidState: (state: State) => boolean
): State[] {
  if (isValidState(state)) {
    return [state];
  }
  return getNextStates(state).flatMap((nextState) =>
    backtrack(nextState, getNextStates, isValidState)
  );
}

function permute(nums: number[]): number[][] {
  const x = backtrack(
    { freq: {}, count: 0 },
    ({ freq, count }) =>
      nums
        .filter((num) => !(num in freq))
        .map((num) => ({
          freq: { ...freq, [`${num}`]: count },
          count: count + 1,
        })),
    (state) => state.count === nums.length
  );

  return x.map((state) =>
    Object.entries(state.freq)
      .map(([num, pos]) => ({ num: Number.parseInt(num), pos: pos as number }))
      .sort((a, b) => a.pos - b.pos)
      .map((e) => e.num)
  );
}
// @lc code=end
