package main

func isHappy(n int) bool {
	squares := []int{0,1,4,9,16,25,36,49,64,81}
	counter := make(map[int]int)
	for n != 1 {
		num := 0
		for n > 0 {
			num += squares[n%10]
			n = n / 10
		}
		n = num
		_ ,ok := counter[n]
		if ok {
			return false
		} else {
			counter[n] = 1
		}
	}
	return true
}


func main() {
	println(isHappy(17))
}
