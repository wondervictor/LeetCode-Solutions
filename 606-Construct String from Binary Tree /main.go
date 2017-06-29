package main

import "fmt"

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

//func traverse(t *TreeNode, str *string) {
//	*str = *str + "("
//
//
//}

func tree2str(t *TreeNode) string {
	if t == nil {
		return ""
	}
	str := ""
	str = fmt.Sprint("", t.Val)
	if t.Left != nil || (t.Left == nil && t.Right != nil) {
		str += "("
		leftStr := tree2str(t.Left)
		str += leftStr
		str += ")"
	}
	if t.Right != nil {
		str += "("
		rightStr := tree2str(t.Right)
		str += rightStr
		str += ")"
	}
	return str
}


func main() {

}
