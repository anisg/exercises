/*
 * @lc app=leetcode id=40 lang=typescript
 *
 * [40] Combination Sum II
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

function combinationSum2(candidates: number[], target: number): number[][] {}
// @lc code=end
