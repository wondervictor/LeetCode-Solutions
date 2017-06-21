package main


func findPeakElement(nums []int) int {
	size := len(nums)
	if size == 1 {
		return 0
	}
	for i := 1; i < size-1; i = i + 1 {
		if nums[i] > nums[i+1] && nums[i] > nums[i-1] {
			return i
		}
	}
	if nums[size-1] > nums[size-2] {
		return size-1
	}
	return 0
}

func main() {

}
