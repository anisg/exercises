/*
 * @lc app=leetcode id=102 lang=typescript
 *
 * [102] Binary Tree Level Order Traversal
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

function levelOrder(root: TreeNode | null): number[][] {
  if (!root) return [];
  return dfsVisit(root, 1)
    .sort((a, b) => a.depth - b.depth)
    .reduce(
      (res, val) => {
        if (val.depth != res.length) {
          res.push([]);
        }
        res[res.length - 1].push(val.value);
        return res;
      },
      [[]] as number[][]
    );
  function dfsVisit(
    node: TreeNode | null,
    depth
  ): { depth: number; value: number }[] {
    if (!node) return [];
    const left = dfsVisit(node.left, depth + 1);
    const right = dfsVisit(node.right, depth + 1);
    return [{ depth: depth, value: node.val }, ...left, ...right];
  }
}
// @lc code=end
