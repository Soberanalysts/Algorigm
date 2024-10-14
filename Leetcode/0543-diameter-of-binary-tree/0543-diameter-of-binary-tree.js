/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var diameterOfBinaryTree = function(root) {
    let distance=0;
    function dfs(node){
        if (node === null) {
            return 0;
        }

        let left = dfs(node.left);
        let right = dfs(node.right);

        distance=Math.max(distance, left+right);
        return 1 + Math.max(left,right);
    }
    
    dfs(root);
    return distance;
};