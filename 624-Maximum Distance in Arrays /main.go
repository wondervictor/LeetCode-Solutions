package main


func maxValue(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func minValue(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func maxDistance(arrays [][]int) int {
	nums := len(arrays)
	size := len(arrays[0])
	var max, min int
	if size > 0 {
		min = arrays[0][0]
		max = arrays[0][size-1]
	}
	var diff int
	for i := 1; i < nums; i = i + 1 {
		size = len(arrays[i])
		if size == 0 {
			continue
		}
		diff1 := arrays[i][size-1] - min
		diff2 := max - arrays[i][0]
		diff = maxValue(diff, maxValue(diff1, diff2))
		max = maxValue(max, arrays[i][size-1])
		min = minValue(min, arrays[i][0])
	}
	return diff
}

//func maxDistance(arrays [][]int) int {
//	nums := len(arrays)
//	size := len(arrays[0])
//	var max, min int
//
//	if size > 0 {
//		min = arrays[0][0]
//		max = arrays[0][size-1]
//	}
//	var diff = 0
//	var diff1, diff2 int
//	for i := 1; i < nums; i = i + 1 {
//		size = len(arrays[i])
//		if size == 0 {
//			continue
//		}
//		if min > arrays[i][0] {
//			diff1 = max-arrays[i][0]
//		}
//		if max < arrays[i][size-1] {
//			diff2 = arrays[i][size-1]-min
//		}
//		if diff1 > diff && diff1 > diff2 {
//			min = arrays[i][0]
//			diff = diff1
//			continue
//		}
//		if diff2 > diff && diff2 > diff1 {
//			max = arrays[i][size-1]
//			diff = diff2
//		}
//
//	}
//	return max-min
//}

func main() {


}
