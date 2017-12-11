package main

func findMin1(nums []int) int {
	min := nums[0]
	for i := 0; i < len(nums)-1; i = i + 1 {
		if nums[i] > nums[i+1] {
			min = nums[i + 1]
			break
		}
	}
	return min
}

func findMin(nums []int) int {
	size := len(nums)
	low := 0
	high := size-1
	for low < high {
		mid := (low + high)/2
		if nums[mid] > nums[high] {
			low = mid + 1
		} else {
			high = mid
		}
	}
	return nums[low]
}



func main() {

}
