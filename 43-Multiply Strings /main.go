package main

import (
	"strconv"
)

//import "fmt"

func add(num1 *string, num2 *string) string {
	len1 := len(*num1)
	len2 := len(*num2)
	resultStr := ""
	carry := 0
	if len1 >= len2 {
		for i := len1-1; i >= 0; i-=1 {
			a := int((*num1)[i] - '0')
			b := 0
			if i + len2 - len1 >= 0 {
				b = int((*num2)[i-len1 + len2] - '0')
			}
			res := a + b + carry
			carry = res / 10
			res = res % 10
			resultStr = strconv.Itoa(res) + resultStr
		}
	} else {
		for i := len2-1; i >= 0; i-=1 {
			a := 0
			if i + len1 - len2 >= 0 {
				a = int((*num1)[i + len1 - len2] - '0')
			}
			b := int((*num2)[i] - '0')
			res := a + b + carry
			carry = res / 10
			res = res % 10
			resultStr = strconv.Itoa(res) + resultStr
		}
	}
	resultStr = strconv.Itoa(carry) + resultStr
	
	//if carry > 0 {
	//	resultStr = strconv.Itoa(carry) + resultStr
	//}
	return resultStr
}

func multiplyBySingle(num1 *string, mutiplier int) string {
	resultStr := ""
	carry := 0
	for i := len(*num1)-1; i >= 0; i -= 1 {
		m := int((*num1)[i] - '0') * mutiplier + carry
		carry = m / 10
		m = m % 10
		resultStr = strconv.Itoa(m) + resultStr
	}
	resultStr = strconv.Itoa(carry) + resultStr
	return resultStr
}

func appenZero(num1 *string, n int) {
	zeroStr := ""
	for n > 0 {
		zeroStr += strconv.Itoa(0)
		n -= 1
	}
	*num1 = *num1 + zeroStr
}

func multiply(num1 string, num2 string) string {
	numLen1 := len(num1)
	numLen2 := len(num2)
	resultStr := ""
	if numLen1 >= numLen2 {
		for i := numLen2-1; i >= 0; i -= 1 {
			n := int(num2[i] - '0')
			currentStr := multiplyBySingle(&num1, n)
			appenZero(&currentStr, numLen2-1-i)
			resultStr = add(&resultStr, &currentStr)
		}
	} else {
		for i := numLen1-1; i >= 0; i -= 1 {
			n := int(num1[i] - '0')
			currentStr := multiplyBySingle(&num2, n)
			appenZero(&currentStr, numLen1-1-i)
			resultStr = add(&resultStr, &currentStr)
		}
	}
	index := 0
	for resultStr[index] == '0' && index < len(resultStr)-1{
		index += 1
	}
	resultStr = resultStr[index:]
	return resultStr
}


func main() {
	
	n1 := "2432505324462141"
	//n2 := 2
	n2 := "1412352562141324"
	m := multiply(n1, n2)
	
	//m := multiplyBySingle(&n1, n2)
	//m := add(&n1, &n2)
	println(m)
}