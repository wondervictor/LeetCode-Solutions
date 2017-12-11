package main

import "sort"

func maximumProduct(nums []int) int {
	if len(nums) < 3 {
		return 0
	} else if len(nums) == 3 {
		return nums[0]*nums[1]*nums[2]
	}
	sort.Ints(nums)
	size := len(nums)
	max1 := 0
	if nums[1] < 0 && nums[size-1] > 0 {
		max1 = nums[0]*nums[1]*nums[size-1]
	}
	max2 := nums[size-3]*nums[size-2]*nums[size-1]
	
	if max1 > max2 {
		return max1
	} else {
		return max2
	}
	
}


func main() {


}
