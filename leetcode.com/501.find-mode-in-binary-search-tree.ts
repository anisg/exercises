/*
 * @lc app=leetcode id=501 lang=typescript
 *
 * [501] Find Mode in Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function findMode(root: TreeNode | null): number[] {
  let visitCountMap: Record<string, number> = {};

  dfs(root);

  return Object.entries(visitCountMap)
    .sort((a, b) => b[1] - a[1])
    .reduce((res, cur) => {
      if (!res.length || res[0][1] === cur[1]) {
        res.push(cur);
      }
      return res;
    }, [] as any)
    .map((x) => Number.parseInt(x[0]));

  function dfs(node: TreeNode | null) {
    if (!node) {
      return;
    }
    visitCountMap[`${node.val}`] = (visitCountMap[`${node.val}`] || 0) + 1;
    dfs(node.left);
    dfs(node.right);
  }
}
// @lc code=end
