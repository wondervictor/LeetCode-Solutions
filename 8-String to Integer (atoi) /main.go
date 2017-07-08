package main

import (
	//"strconv"
	"fmt"
	"math"
)

func myAtoi(str string) int {
	size := len(str)
	num := 0
	INT_MAX := 2147483647
	INT_MIN := -2147483648
	state := 0
	bigNum := false
	multiplier := 0
	
	for i := size-1; i >= 0; i -= 1 {
		if str[i] <= '9' && str[i] >='0' {
			if state == 5 {
				num = 0
				multiplier = 0
			}
			state = 0
			tmp := int(str[i]-'0') * int(math.Pow(10, float64(multiplier)))
			
			if tmp > 8 * INT_MAX || tmp <  8 * INT_MIN {
				num = INT_MAX
				bigNum = true
			} else {
				num = num + tmp
			}
			multiplier += 1
			
		} else if str[i] == '-' {
			if state == 4 || state == 5 || state==1 {
				num = 0
				multiplier = 0
			}
			if bigNum {
				if num > 0 {
					num = INT_MIN
				} else {
					num = INT_MAX
				}
			} else {
				num = -num
			}
			state = 1
			
		} else if str[i] == '+' {
			if state > 0 {
				num = 0
				multiplier = 0
			}
			state = 4
		} else if str[i] == ' ' {
			state = 5
		} else {
			num = 0
			multiplier = 0
		}
	}
	
	if num > INT_MAX {
		num = INT_MAX
	} else if num < INT_MIN {
		num = INT_MIN
	}
	return num
}


func main() {
	//t := "18446744073709551617"
	
	s := "      -11919730356x"
	//num1, err := strconv.Atoi(s)
	num2 := myAtoi(s)
	//if err != nil {
	//	fmt.Println(err)
	//} else {
	//	fmt.Println(num1)
	//	fmt.Println(num2)
	//}
	//
	fmt.Println(num2)
	
	
}
