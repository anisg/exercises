/*
 * @lc app=leetcode id=47 lang=typescript
 *
 * [47] Permutations II
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

function permuteUnique(nums: number[]): number[][] {
  const numsMap = {};
  nums.forEach((num) => {
    numsMap[num] = (numsMap[num] || 0) + 1;
  });

  const x = backtrack(
    {
      freq: {} as Record<number, number[]>,
      count: 0,
      countMap: {} as Record<number, number>,
    },
    ({ freq, count, countMap }) =>
      Object.keys(numsMap)
        .filter((num) => (countMap[num] || 0) < numsMap[num])
        .map((num) => ({
          freq: { ...freq, [num]: [...(freq[num] || []), count] },
          countMap: { ...countMap, [num]: (countMap[num] || 0) + 1 },
          count: count + 1,
        })),
    (state) => state.count === nums.length
  );

  return x.map((state) =>
    Object.entries(state.freq)
      .flatMap(([num, arrPos]) =>
        arrPos.map((pos) => ({ num: Number.parseInt(num), pos: pos as number }))
      )
      .sort((a, b) => a.pos - b.pos)
      .map((e) => e.num)
  );
}
// @lc code=end
