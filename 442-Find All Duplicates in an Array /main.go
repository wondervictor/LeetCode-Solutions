package main



// hash method
func findDuplicates1(nums []int) []int {
	size := len(nums)
	count := make(map[int]int, size)
	for i := 0; i < size; i = i + 1 {
		count[nums[i]] = count[nums[i]] + 1
	}
	s := make([]int,0)
	for key, value := range count {
		if value >= 2 {
			s = append(s,key)
		}
	}
	return s
}

/** only one can be found
func findDuplicates(nums []int) []int {
	size := len(nums)
	result := make([]int, 0)
	
	for i := 0; i < size; {
		num := nums[i]
		for i != nums[i]-1 {
			if num == nums[num-1] {
				result = append(result, num)
			} else {
				temp := nums[i]
				nums[i] = nums[num-1]
				nums[num-1] = temp
			}
		}
	}
	return result
}
*/

func findDuplicates(nums []int) []int {
	size := len(nums)
	result := make([]int, 0)
	
	for i := 0; i < size; {
		if nums[i] != nums[nums[i]-1] {
			m := nums[i]
			temp := nums[i]
			nums[i] = nums[m-1]
			nums[m-1] = temp
		} else {
			i = i + 1
		}
	}
	for i := 0; i < size; i = i + 1 {
		if i != nums[i]-1 {
			result = append(result, nums[i])
		}
	}
	return result

}


func main() {

}
