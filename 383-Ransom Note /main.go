package main


func canConstruct1(ransomNote string, magazine string) bool {
	counter := make(map[byte]int)
	size1 := len(ransomNote)
	size2 := len(magazine)
	if size2 < size1 {
		return false
	}
	for i := 0; i < size2; i ++ {
		_, ok := counter[magazine[i]]
		if ok {
			counter[magazine[i]] += 1
		} else {
			counter[magazine[i]] = 1
		}
	}
	for i := 0; i < size1; i ++ {
		counter[ransomNote[i]] --
		if counter[ransomNote[i]] < 0 {
			return false
		}
	}
	return true
}

func main() {


}
