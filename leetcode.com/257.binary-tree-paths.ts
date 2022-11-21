/*
 * @lc app=leetcode id=257 lang=typescript
 *
 * [257] Binary Tree Paths
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

function binaryTreePaths(root: TreeNode | null): string[] {
  return dfs(root, []);

  function dfs(node, path: TreeNode[]): string[] {
    if (!node) return [];
    if (node.left == null && node.right == null) {
      return [[...path, node].map((e) => e.val).join("->")];
    }
    return [
      ...dfs(node.left, [...path, node]),
      ...dfs(node.right, [...path, node]),
    ];
  }
}
// @lc code=end
