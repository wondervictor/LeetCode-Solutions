package main

import "math"

//Definition for a binary tree node.
type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

func traverse(root *TreeNode) (int,int) {
	if root.Right == nil && root.Left == nil {
		return root.Val, 0
	} else if root.Right != nil && root.Left == nil {
		sum, til := traverse(root.Right)
		return root.Val + sum, int(math.Abs(float64(sum))) + til
	} else if root.Right == nil && root.Left != nil {
		sum, til := traverse(root.Left)
		return root.Val + sum, int(math.Abs(float64(sum))) + til
	} else {
		sumLeft, tilLeft := traverse(root.Left)
		sumRight, tilRight := traverse(root.Right)
		return root.Val + sumLeft + sumRight, tilLeft + tilRight + int(math.Abs(float64(sumLeft-sumRight)))
	}
}

func findTilt(root *TreeNode) int {
	if root == nil {
		return 0
	}
	_, til := traverse(root)
	return til
}

func main() {

}
