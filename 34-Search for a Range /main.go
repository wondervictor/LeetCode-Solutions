package main

func searchRange(nums []int, target int) []int {
	result := make([]int,2)
	size := len(nums)
	lo := 0
	hi := size
	currentPostion := -1
	for lo < hi {
		mid := (lo + hi) / 2
		if nums[mid] == target {
			currentPostion = mid
			break
		}
		if nums[mid] < target {
			lo = mid + 1
			continue
		}
		if nums[mid] > target {
			hi = mid
			continue
		}
	}
	if currentPostion == -1 {
		result[0] = -1
		result[1] = -1
	} else {
		i := currentPostion
		for i >= 0 && nums[i] == target {
			i = i - 1
		}
		result[0] = i + 1
		j := currentPostion
		for j < size && nums[j] == target {
			j = j + 1
		}
		result[1] = j - 1
	}
	return result
}

func main() {

}
