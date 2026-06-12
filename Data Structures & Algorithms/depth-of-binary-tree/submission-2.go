/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
// recursive dfs
func maxDepth_1(root *TreeNode) int {
    if root == nil{
		return 0
	}
	lDepth := maxDepth(root.Left)
	rDepth := maxDepth(root.Right)
	return 1+max(lDepth,rDepth)
}

// bfs
func maxDepth(root *TreeNode) int {
	if root == nil{
		return 0
	}
	q := []*TreeNode{root}
	depth := 0
	for len(q)>0{
		size := len(q)
		for i:=0;i<size;i++{
			node := q[0]
			q = q[1:]
			
			if node.Left != nil{
				q = append(q,node.Left)
			}
			if node.Right != nil{
				q = append(q,node.Right)
			}
		}
		depth++
	}
	return depth
}
