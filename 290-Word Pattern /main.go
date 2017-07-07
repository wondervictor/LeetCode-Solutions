package main

func check(patterns *map[byte]string, key byte, str *string) bool {
	val, ok := (*patterns)[key]
	if !ok {
		(*patterns)[key] = *str
		return true
	} else {
		if val != *str {
			return false
		} else {
			return true
		}
	}
}

func checkDepulicate(patterns *map[byte]string) bool {
	tmp := make(map[string]byte)
	for k, v := range *patterns {
		val, ok := tmp[v]
		if ok {
			if val == tmp[v] {
				return false
			}
		} else {
			tmp[v] = k
		}
	}
	return true
}

func wordPattern(pattern string, str string) bool {
	patterns := make(map[byte]string)
	valueStr := ""
	k := 0
	for i:=0; i<len(str); i += 1 {
		if str[i] == ' ' {
			if k >= len(pattern) {
				return false
			}
			if check(&patterns, pattern[k], &valueStr) {
				valueStr = ""
				k += 1
			} else {
				return false
			}

		} else {
			valueStr = valueStr + string(str[i])
		}
	}
	if k >= len(pattern) || k < len(pattern)-1{
		return false
	}
	if !check(&patterns, pattern[k], &valueStr) {
		return false
	}
	return checkDepulicate(&patterns)
}

func main() {
	str1 := "aabbb"
	str2 := "dog dog cat cat d"
	println(wordPattern(str1, str2))
}
