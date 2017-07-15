package main

import (
	"strconv"
	"fmt"
)


// convert to string
func isPalindrome1(x int) bool {
	if x < 0 {
		return false
	}
	xStr := strconv.Itoa(x)
	size := len(xStr)
	for i := 0; i < size/2; i ++ {
		if xStr[i] != xStr[size-1-i] {
			return false
		}
	}
	return true
}

func isPalindrome(x int) bool {
	if x < 0 {
		return false
	}
	p := x
	q := 0
	
	for p > 0 {
		q *= 10
		q += p%10
		p /= 10
	}
	return q == x
}


func main() {

	p := 123321
	fmt.Println(isPalindrome(p))
	
}
