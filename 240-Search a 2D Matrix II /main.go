package main


func searchInVector(vector []int, target int) bool {
	dim := len(vector)
	left := 0
	right := dim-1
	for left <= right {
		mid := (left + right) / 2
		if (vector)[mid] == target {
			return true
		} else if (vector)[mid] > target {
			right = mid - 1
		} else if (vector)[mid] < target {
			left = mid + 1
		}
	}
	return false
}

func searchMatrix(matrix [][]int, target int) bool {
	dimX := len(matrix)
	if dimX == 0 {
		return false
	}
	dimY := len(matrix[0])
	if dimY == 0 {
		return false
	}
	for i := 0; i < dimX; i += 1 {
		if matrix[i][0] <= target && matrix[i][dimY-1] >= target {
			if searchInVector(matrix[i], target) {
				return true
			}
		}
	}
	return false
}



func main() {

}
