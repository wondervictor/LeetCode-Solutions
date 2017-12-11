package main

// math
func getUniqueDigits(n int) int {
	if n == 0 {
		return 1
	} else if n == 1 {
		return 10
	} else if n <= 10 {
		var A int = 1
		for i := 0; i <= n-2; i = i + 1 {
			A = A * (9-i)
		}
		return A * 9
	} else  {
		return 0
	}
}

func countNumbersWithUniqueDigits(n int) int {
	var sum = 0
	for i := 1; i <= n; i = i + 1 {
		sum = sum + getUniqueDigits(i)
	}
	return sum
}

func main() {



}
