package main

import "sort"

func dist(p1, p2 []int) int {
	return (p1[0] - p2[0])*(p1[0] - p2[0]) + (p1[1] - p2[1])*(p1[1] - p2[1])
}

func validSquare(p1 []int, p2 []int, p3 []int, p4 []int) bool {
	distance := make([]int, 6)
	distance[0] = dist(p1,p2)
	distance[1] = dist(p1,p3)
	distance[2] = dist(p1,p4)
	distance[3] = dist(p2,p3)
	distance[4] = dist(p2,p4)
	distance[5] = dist(p3,p4)
	
	if distance[0] == 0 {
		return false
	}
	sort.Ints(distance)
	for i := 1; i < 4; i = i + 1 {
		if distance[i] != distance[i-1] {
			return false
		}
	}
	for i := 4; i < 5; i = i + 1 {
		if distance[i] != 2 * distance[3] {
			return false
		}
	}
	return true
}

func main() {

}
