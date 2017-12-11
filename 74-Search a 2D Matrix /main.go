package main

import "fmt"

func searchInVector(mat [][]int, target, index int) bool {
	dim := len(mat[index])
	left := 0
	right := dim-1
	for left <= right {
		mid := (left + right) / 2
		if mat[index][mid] == target {
			return true
		} else if mat[index][mid] > target {
			right = mid - 1
		} else if mat[index][mid] < target {
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
	
	up := 0
	down := dimX-1
	for up <= down {
		mid := (down + up)/2
		if matrix[mid][0] == target {
			return true
		}
		if matrix[mid][0] > target {
			down = mid-1
		} else if matrix[mid][0] < target {
			if matrix[mid][dimY-1] == target {
				return true
			} else if matrix[mid][dimY-1] > target {
				return searchInVector(matrix, target, mid)
			} else {
				up = mid + 1
			}
		}
	}
	return false
}

func main() {

}
