/*
 * @lc app=leetcode id=337 lang=typescript
 *
 * [337] House Robber III
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

function rob(root: TreeNode | null): number {
  const r = dfs(root);

  return Math.max(r.robChildrenCount, r.robDirectCount);

  function dfs(node): { robDirectCount: number; robChildrenCount: number } {
    if (!node) {
      return { robDirectCount: 0, robChildrenCount: 0 };
    }
    const c1 = dfs(node.left);
    const c2 = dfs(node.right);
    return {
      robDirectCount: node.val + c1.robChildrenCount + c2.robChildrenCount,
      robChildrenCount:
        0 +
        Math.max(c1.robDirectCount, c1.robChildrenCount) +
        Math.max(c2.robDirectCount, c2.robChildrenCount),
    };
  }
}
// @lc code=end
