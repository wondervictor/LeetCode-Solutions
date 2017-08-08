package main

import "fmt"

func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}
	counter := make(map[byte]int)
	for i := 0; i < len(s); i ++ {
		_, ok := counter[s[i]]
		if !ok {
			counter[s[i]] = 0
		}
		counter[s[i]] += 1
	}
	tmp := len(s)
	for i := 0; i < len(t); i ++ {
		v, ok := counter[t[i]]
		if ok && v > 0 {
			counter[t[i]] --
			tmp --
		} else {
			return false
		}
	}
	return tmp == 0
}


func main() {
	s := "a"
	p := "b"
	fmt.Print(isAnagram(s,p))
}
