package main

import (
	"container/list"
	"fmt"
)

// violent solution
func nextGreaterElement1(findNums []int, nums []int) []int {
	size1 := len(findNums)
	size2 := len(nums)
	result := make([]int, size1)
	for i := 0; i < size1; i = i + 1 {
		result[i] = -1
	}
	flag := false
	for i := 0; i < size1; i = i + 1 {
		flag = false
		for j := 0; j < size2; j = j + 1 {
			if flag {
				if nums[j] > findNums[i] {
					result[i] = nums[j]
					flag = false
					break
				}
			}
			if nums[j] == findNums[i] {
				flag = true
			}
		}
	}
	return result
}

// weak method
func nextGreaterElement2(findNums []int, nums []int) []int {
	size1 := len(findNums)
	size2 := len(nums)
	result := make([]int, size1)
	
	nextNum := make(map[int]int, size2)
	
	for i := 0; i < size2; i = i + 1 {
		nextNum[nums[i]] = -1
		for j := i + 1; j < size2; j = j + 1 {
			if nums[j] > nums[i] {
				nextNum[nums[i]] = nums[j]
				break
			}
		}
	}
	
	for i := 0; i < size1; i = i + 1 {
		 result[i] = nextNum[findNums[i]]
	}
	return result
}

func nextGreaterElement(findNums []int, nums []int) []int {
	size1 := len(findNums)
	size2 := len(nums)
	result := make([]int, size1)
	
	nextNum := make(map[int]int, size2)
	stack := list.New()
	for i := 0; i < size2; i = i + 1 {
		nextNum[nums[i]] = -1
		
		for stack.Len()>0 && stack.Back().Value.(int) < nums[i] {
			nextNum[stack.Back().Value.(int)] = nums[i]
			stack.Remove(stack.Back())
		}
		stack.PushBack(nums[i])
	}
	for i := 0; i < size1; i = i + 1 {
		result[i] = nextNum[findNums[i]]
	}
	return result
	
}


func main() {

	s := []int{4,1,2}
	p := []int{1,3,4,2}
	
	m := nextGreaterElement(s,p)
	fmt.Print(m)


}
