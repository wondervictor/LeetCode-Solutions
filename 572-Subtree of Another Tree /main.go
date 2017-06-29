package main

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}


func traverse(s *TreeNode, t *TreeNode) bool {
	if s.Val == t.Val {
		right := false
		left := false
		if s.Right != nil && t.Right != nil {
			right = traverse(s.Right, t.Right)
		} else if s.Right == nil && t.Right == nil {
			right = true
		} else {
			right = false
		}
		
		if s.Left != nil && t.Left != nil {
			left = traverse(s.Left, t.Left)
		} else if s.Left == nil && t.Left == nil {
			left = true
		} else {
			right = false
		}
		return right && left
	} else {
		return false
	}
}

func isSubtree(s *TreeNode, t *TreeNode) bool {
	currentLeftRes := false
	currentRightRes := false
	currentRes := false
	traverseRes := false
	if s.Left != nil {
		currentLeftRes = isSubtree(s.Left,t)
	}
	if s.Right != nil {
		currentRightRes = isSubtree(s.Right, t)
	}
	currentRes = currentRightRes || currentLeftRes
	if s.Val == t.Val {
		traverseRes = traverse(s,t)
	}
	return currentRes || traverseRes
}


func main() {



}
