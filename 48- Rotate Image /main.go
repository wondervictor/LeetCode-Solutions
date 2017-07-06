package main

import "fmt"

func rotate(matrix [][]int)  {
	size := len(matrix)
	
	for i := 0; i < size/2; i ++ {
		rectSize := size-2*i
		for j := 0; j < rectSize-1; j ++ {
			tmp := matrix[i+rectSize-1][j+i] //matrix[i+j][i]
			matrix[i+rectSize-1][j+i] = matrix[rectSize-1-j+i][rectSize-1+i]
			matrix[rectSize-1-j+i][rectSize-1+i]=matrix[i][rectSize-j-1+i]
			matrix[i][rectSize-j-1+i] = matrix[i+j][i]
			matrix[i+j][i] = tmp
		}
	}
}
