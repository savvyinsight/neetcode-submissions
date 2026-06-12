/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func diameterOfBinaryTree(root *TreeNode) int {
    if root == nil{
		return 0
	}
	lHeight := maxHeight(root.Left)
	rHeight := maxHeight(root.Right)
	diameter := lHeight + rHeight
	sub := max(diameterOfBinaryTree(root.Left),diameterOfBinaryTree(root.Right))
	return max(diameter,sub) 
}

func maxHeight(root *TreeNode) int{
	if root == nil{
		return 0
	}
	lH := maxHeight(root.Left)
	rH := maxHeight(root.Right)
	return 1 + max(lH,rH)
}
