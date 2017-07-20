package main

func spiralOrder(matrix [][]int) []int {
	result := make([]int, 0)
	height := len(matrix)
	if height < 1 {
		return result
	}
	width := len(matrix[0])
	x := 0
	subHeight := height
	subWidth := width
	for subWidth > 1 && subHeight > 1 {
		for i := 0; i < subWidth-1; i ++ {
			result = append(result, matrix[x][x+i])
		}
		for i := 0; i < subHeight-1; i ++ {
			result = append(result, matrix[x+i][x+subWidth-1])
		}
		for i := subWidth-1; i >= 1; i -- {
			result = append(result, matrix[x+subHeight-1][x+i])
		}
		for i := subHeight-1; i >= 1; i -- {
			result = append(result, matrix[x+i][x])
		}
		x = x + 1
		subWidth = subWidth-2
		subHeight = subHeight-2
	}
	if subWidth == 1 && subHeight == 1 {
		result = append(result, matrix[x][x])
	} else if subHeight == 1 && subWidth > 1 {
		for i := 0; i < subWidth; i ++ {
			result = append(result, matrix[x][x+i])
		}
	} else if subWidth == 1 && subHeight > 1 {
		for i := 0; i < subHeight; i ++ {
			result = append(result, matrix[x+i][x])
		}
	}
	return result
}

func main() {

}
