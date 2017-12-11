package main

import (
	"sort"
	"fmt"
)

func searchNum(nums *[]int, start, end, num int) int {
	for start <= end {
		mid := (start + end)/2
		if (*nums)[mid] + num == 0 {
			return mid
		} else if (*nums)[mid] + num < 0 {
			start = mid + 1
		} else if (*nums)[mid] + num > 0 {
			end = mid - 1
		}
	}
	return -1
}

func threeSum(nums []int) [][]int {
	resultMap := make(map[[3]int]int,0)
	size := len(nums)
	sort.Ints(nums)
	fmt.Println(nums)
	for i := 0; i < size-2; i += 1 {
		for j := i + 1; j < size-1; j += 1 {
			num := nums[i] + nums[j]
			s := searchNum(&nums, j+1, size-1,num)
			if s > 0 {
				arr := [3]int{nums[i], nums[j], nums[s]}
				resultMap[arr] = 1
			}
		}
	}
	result := make([][]int,0)
	for k, _ := range resultMap {
		result = append(result, []int{k[0],k[1],k[2]})
		
	}
	return result
}


func main() {
	s := []int{-1,0,1,2,-1,-4,-5,1,-4,5,10}
	fmt.Println(threeSum(s))
}
