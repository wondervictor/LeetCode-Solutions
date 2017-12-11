package main

import "sort"

func check(a,b,c int) int {
	if a + b > c {
		return 1
	}
	return 0
}

func binarySearch(nums *[]int, start, end, target int) int {
	left := start
	right := end
	for left <= right {
		mid := (left + right) / 2
		if (*nums)[mid] >= target {
			right = mid-1
		} else {
			left = mid + 1
		}
	}
	return left
}

func triangleNumber(nums []int) int {
	count := 0
	size := len(nums)
	sort.Ints(nums)
	for i := 0; i < size-2; i = i + 1 {
		for j := i + 1; j < size-1; j = j + 1 {
			third := binarySearch(&nums, j+1, size-1,nums[j]+nums[i])
			count += third- j - 1
		}
	}
	return count
}





func triangleNumber1(nums []int) int {
	count := 0
	size := len(nums)
	sort.Ints(nums)
	for i := 0; i < size-2; i = i + 1 {
		for j := i+1; j < size-1; j = j + 1 {
			for k := j + 1; k < size; k = k + 1 {
				count = count + check(nums[i],nums[j],nums[k])
			}
		}
	}
	return count
}



func main() {

}
