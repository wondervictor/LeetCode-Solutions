package main

import "fmt"

func singleNumber(nums []int) int {
	times := make(map[int]int)
	size := len(nums)
	for i := 0; i < size; i += 1 {
		_, ok := times[nums[i]]
		if ok {
			times[nums[i]] += 1
		} else {
			times[nums[i]] = 1
		}
	}
	for i,v := range times {
		if v < 3 {
			return i
		}
	}
	return 0
}

func main() {
	s := []int{1,3,3,3,4,7,4,8,5,6,8,4,7,8,7,6,5,6,5}
	fmt.Println(singleNumber(s))
}
