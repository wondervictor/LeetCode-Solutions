package main


func findLHS(nums []int) int {
	counter := make(map[int]int)
	
	for i:=0; i < len(nums); i ++ {
		_, ok := counter[nums[i]]
		if !ok {
			counter[nums[i]] = 0
		}
		counter[nums[i]] += 1
	}
	length := 0
	for i, v := range counter {
		subVal, ok := counter[i-1]
		if ok {
			if subVal + v > length {
				length = subVal + v
			}
		}
		subVal, ok = counter[i+1]
		if ok {
			if subVal + v > length {
				length = subVal + v
			}
		}
		
	}
	return length
}

func main() {


}

