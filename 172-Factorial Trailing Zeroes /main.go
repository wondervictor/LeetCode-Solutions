package main



func trailingZeroes(n int) int {
	result := 0
	for i := 5; n / i > 0; i *= 5 {
		result += n / i
	}
	return result
}


func main() {

}
