package main

import "fmt"

func combine(numberMap *map[byte][]string, digit string, index int) []string {
	letters := (*numberMap)[digit[index]]
	size := len(letters)
	if index == len(digit)-1 {
		return letters
	}
	if size == 0 {
		return combine(numberMap, digit, index+1)
	} else {
		subResult := combine(numberMap, digit, index + 1)
		if len(subResult) > 0 {
			result := make([]string,0)
			for i := 0; i < len(subResult); i ++ {
				for j := 0; j < size; j ++ {
					result = append(result, (*numberMap)[digit[index]][j]+subResult[i])
				}
			}
			return result
		} else {
			return letters
		}
	}
}

func letterCombinations(digits string) []string {
	if len(digits) == 0 {
		return []string{}
	}
	numberMap := map[byte][]string{
	'2': {"a", "b", "c"},
	'3': {"d", "e", "f"},
	'4': {"g", "h", "i"},
	'5': {"j", "k", "l"},
	'6': {"m", "n", "o"},
	'7': {"p", "q", "r", "s"},
	'8': {"t", "u", "v"},
	'9': {"w", "x", "y", "z"},
	'0': {},
	'#': {},
	'1': {},
	'*': {},
	}
	m := combine(&numberMap, digits, 0)
	return m
}

func main() {
	fmt.Println(letterCombinations("23524#"))
	
}
