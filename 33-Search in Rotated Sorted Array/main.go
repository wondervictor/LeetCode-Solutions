package main

import "fmt"

func search1(nums []int, target int) int {
	for i, v := range nums {
		if v == target {
			return i
		}
	}
	return -1
}



func search(nums []int, target int) int {
	low := 0
	size := len(nums)
	high := size-1
	for low <= high {
		mid := (low + high)/2
		if nums[mid] == target {
			return mid
		}
		
		if nums[mid] >= nums[low] {
			if nums[mid] > target  && target >= nums[low] {
				high = mid
				continue
			}
			if nums[mid] < target {
				low = mid + 1
				continue
			}
			if target < nums[low] {
				low = mid + 1
				continue
			}
			break
		} else{
			if nums[mid] <= target && target >= nums[low] {
				high = mid
				continue
			}
			if target <= nums[low] && target <= nums[mid] {
				high = mid
				continue
			}
			if target <= nums[low] && target >= nums[mid] {
				low = mid + 1
				continue
			}
			
			break
		}
	}
	return -1
}

func main() {
	s := []int {12,23,45,56,67,0,1,2,3,4,5,6,7}
	num := 67
	p := search(s,num)
	m := search1(s,num)
	
	fmt.Println(p)
	fmt.Println(m)
	if p != m {
		println("false")
	} else {
		println("yes")
	}
}
