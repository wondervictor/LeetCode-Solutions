package main



type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

func traverseTree(t1 *TreeNode, t2 *TreeNode) {
	t2.Val = t2.Val + t1.Val
	if t1.Left != nil {
		if t2.Left == nil {
			t2.Left = &TreeNode{
				Val:0,
				Left:nil,
				Right:nil,
			}
		}
		traverseTree(t1.Left, t2.Left)
	}
	if t1.Right != nil {
		if t2.Right == nil {
			t2.Right = &TreeNode{
				Val:0,
				Left:nil,
				Right:nil,
			}
		}
		traverseTree(t1.Right, t2.Right)
	}
}


func mergeTrees(t1 *TreeNode, t2 *TreeNode) *TreeNode {
	if t2 == nil {
		return t1
	} else if t1 == nil {
		return t2
	}
	traverseTree(t1, t2)
	return t2
}

func main() {

}
