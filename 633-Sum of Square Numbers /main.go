package main

import "math"


// TLE
func judgeSquareSum1(c int) bool {
	rootFloat := math.Floor(math.Sqrt(float64(c)))
	rootInt := int(rootFloat)
	for i := rootInt; i > 0; i -- {
		for j := 1; j < rootInt; j ++ {
			if j*j + i*i == c {
				return true
			}
		}
	}
	return false
}

func judgeSquareSum(c int) bool {
	isSquare := func (a int) bool {
		rootFloat := math.Sqrt(float64(a))
		rootFloor := math.Floor(rootFloat)
		if rootFloor - rootFloat == 0 {
			return true
		}
		return false
	}
	if isSquare(c) {
		return true
	}
	for i := 0; i*i < c; i ++ {
		m := c - i * i
		if isSquare(m) {
			return true
		}
	}
	return false
}


func main() {

}

