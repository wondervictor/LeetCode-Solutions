package main



func matrixReshape(nums [][]int, r int, c int) [][]int {
	originHeight := len(nums)
	if originHeight == 0 {
		return nums
	}
	originWidth := len(nums[0])
	if originHeight * originWidth != r * c {
		return nums
	}
	
	result := make([][]int,r)
	currentRow := 0
	currentCol := 0
	for i := 0;i < r; i ++ {
		arr := make([]int,c)
		for j := 0; j < c; j ++ {
			arr[j] = nums[currentRow][currentCol]
			currentCol ++
			if currentCol == originWidth {
				currentRow ++
				currentCol = 0
			}
		}
		result[i] = arr
	}
	return result
}

func main() {



}
