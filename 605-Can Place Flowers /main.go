package main

import "fmt"

func canPlaceFlowers(flowerbed []int, n int) bool {
	currentBlank := 1
	num := len(flowerbed)
	
	for i := 0; i < num; i += 1 {
		if currentBlank > 0 && flowerbed[i] == 1 {
			n -= (currentBlank-1)/2
			currentBlank = 0
		} else if flowerbed[i] == 0 {
			currentBlank += 1
		}
	}
	n -= (currentBlank+1)/2
	if n > 0 {
		return false
	}
	return true
}

func main() {
	s := []int{0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1}
	fmt.Println(canPlaceFlowers(s,8))
}