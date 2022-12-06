/*
 * @lc app=leetcode id=173 lang=typescript
 *
 * [173] Binary Search Tree Iterator
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

class BSTIterator {
  root: TreeNode | null;
  items: number[];
  cursor: number;

  constructor(root: TreeNode | null) {
    this.root = root;

    this.items = dfsgetValue(root).sort((a, b) => a - b);
    this.cursor = 0;
    function dfsgetValue(node: TreeNode | null): number[] {
      if (node === null) return [];
      return [...dfsgetValue(node.left), node.val, ...dfsgetValue(node.right)];
    }
  }

  next(): number {
    return this.items[this.cursor++];
    // function bstSearch(node:TreeNode|null, val:number):number|-1{
    //     if(node === null) return -1;
    //     if(node.val === val) return val;
    //     if(node.val > val) return bstSearch(node.left, val);
    //     if(node.val < val) return bstSearch(node.right, val);
    // }
  }

  hasNext(): boolean {
    return this.cursor < this.items.length;
  }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * var obj = new BSTIterator(root)
 * var param_1 = obj.next()
 * var param_2 = obj.hasNext()
 */
// @lc code=end
