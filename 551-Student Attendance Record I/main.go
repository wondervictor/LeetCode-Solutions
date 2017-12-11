package main

func checkRecord(s string) bool {
	lateNum := 0
	absentNum := 0
	for _, p := range s {
		if p == 'A' {
			lateNum = 0
			absentNum += 1
			if absentNum >= 2 {
				return false
			}
		} else if p == 'L' {
			lateNum += 1
			if lateNum >= 3 {
				return false
			}
		} else {
			lateNum = 0
		}
	}
	return true
}

func main() {

}
