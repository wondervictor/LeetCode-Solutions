package main


func findRestaurant(list1 []string, list2 []string) []string {
	counter := make(map[string]int)
	for i, v := range list1 {
		counter[v] = i
	}
	for i, v := range list2 {
		_, ok := counter[v]
		if ok {
			counter[v] += i
			counter[v] -= len(list2) + len(list1)
		} else {
			counter[v] = i
		}

	}
	minIndex := 0
	bestRes := make([]string,0)
	for _ ,v := range counter {
		if v < minIndex {
			minIndex = v
		}
	}
	for i ,v := range counter {
		if v == minIndex {
			bestRes = append(bestRes, i)
		}
	}
	return bestRes
}

func main() {


}

