package main

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}


func traverse(root *TreeNode, k *int, flag *bool) int {
	rightValue := 0
	leftValue := 0
	if root.Left != nil {
		leftValue = traverse(root.Left, k, flag)
		if *flag == true {
			return leftValue
		}
	}
	*k -= 1
	if *k == 0 {
		*flag = true
		return root.Val
	}
	if root.Right != nil {
		rightValue = traverse(root.Right, k,flag)
		if *flag == true {
			return rightValue
		}
	}
	*flag = false
	return 0
}

func kthSmallest(root *TreeNode, k int) int {
	a := false
	return traverse(root, &k, &a)
}


func main() {



}
