package main


type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}


func traverse(arr *[]int, tree *TreeNode) {
	//if tree.Left == nil && tree.Right == nil {
	//	*arr = append(*arr, tree.Val)
	//	return
	//}
	if tree.Left != nil {
		traverse(arr, tree.Left)
	}
	*arr = append(*arr, tree.Val)
	if tree.Right != nil {
		traverse(arr, tree.Right)
	}
	/*
	if tree.Left != nil {
		tree.Left.traverse(arr)
	}
	if tree.Right != nil {
		tree.Left.traverse(arr)
	}
	*/
	
}

func getMinimumDifference(root *TreeNode) int {
	searchArr := make([]int, 0)
	traverse(&searchArr, root)
	min := searchArr[1]-searchArr[0]
	for i := 2; i < len(searchArr); i = i + 1 {
		diff := searchArr[i]-searchArr[i-1]
		if min > diff {
			min = diff
		}
	}
	return min
}

func main(){

}
