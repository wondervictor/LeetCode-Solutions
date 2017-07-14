package main

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

func traverse(root *TreeNode, val int) int {
	rightSum := 0
	if root.Right != nil {
		rightSum = traverse(root.Right,val)
	} else {
		rightSum = val
	}
	root.Val += rightSum
	leftSum := root.Val
	if root.Left != nil {
		leftSum = traverse(root.Left, root.Val)
	}
	return leftSum
}


func convertBST(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}
	_ = traverse(root,0)
	return root
}



func convertBST(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}
	_ = traverse(root,9)
	return root
}

func main() {

}
