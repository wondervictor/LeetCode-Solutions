package main

import (
	"fmt"
	"strings"
)

func isAlphaNumeric(c byte) bool {
	if c <= '9' && c >= '0' {
		return true
	} else if c <= 'z' && c <= 'a' {
		return true
	} else {
		return false
	}
}

func isPalindrome(s string) bool {
	size := len(s)
	i := 0
	j := size-1
	s = strings.ToLower(s)
	for i <= j {
		for i < j && !isAlphaNumeric(s[i]) {
			i += 1
		}
		for j > i && !isAlphaNumeric(s[j]) {
			j -= 1
		}
		if s[i] == s[j] {
			i += 1
			j -= 1
			continue
		} else {
			return false
		}
	}
	return true
}


func main() {
	
	s := "A man, a plan, a canal: Paama"
	fmt.Print(isPalindrome(s))

}
