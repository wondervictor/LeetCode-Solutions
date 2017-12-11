package main

func replaceWords(dict []string, sentence string) string {
	words := make(map[string]int)
	for _, v := range dict {
		words[v] = 1
	}
	
	currentStr := ""
	newString := ""
	
	length := len(sentence)
	for i := 0; i < length; i ++ {
		if sentence[i] == ' ' {
			str := ""
			for j := 0; j < len(currentStr); j ++ {
				str += string(currentStr[j])
				_, ok := words[str]
				if ok {
					newString += str
					newString += " "
					currentStr = ""
					break
				}
			}
			if len(currentStr) > 0 {
				newString += currentStr
				currentStr = ""
				newString += " "
			}
			
		} else {
			currentStr += string(sentence[i])
		}
	}
	
	str := ""
	for j := 0; j < len(currentStr); j ++ {
		str += string(currentStr[j])
		_, ok := words[str]
		if ok {
			newString += str
			return newString
		}
	}
	newString += currentStr
	return newString
}


func main() {


}
