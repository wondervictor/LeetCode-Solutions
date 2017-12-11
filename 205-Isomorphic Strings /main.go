package main

func isIsomorphic(s string, t string) bool {
	characters := make(map[byte]byte)
	characterNums := make(map[byte]int)
	
	size := len(s)
	
	for i := 0; i < size; i ++{
		v, ok := characters[s[i]]
		if ok {
			if t[i] != v {
				return false
			}
		} else {
			_, ok := characterNums[t[i]]
			if ok {
				return false
			} else {
				characters[s[i]] = t[i]
				characterNums[t[i]] = 1
			}
		}
	}
	
	return true
}

func main() {

}
