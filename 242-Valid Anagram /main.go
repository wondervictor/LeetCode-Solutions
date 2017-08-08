package main

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
		v, ok := counter[s[i]]
		if ok && v > 1 {
			counter[s[i]] --
			tmp --
		} else {
			return false
		}
	}
	return tmp == 0
}


func main() {

}
