package main

func islandPerimeter(grid [][]int) int {
	perimeter := 0
	rows := len(grid)
	if rows == 0 {
		return 0
	}
	cols := len(grid[0])
	
	for i := 0; i < rows; i = i + 1 {
		for j := 0; j < cols; j = j + 1 {
			if grid[i][j] == 1 {
				if i == 0  {
					perimeter = perimeter + 1
				}
				if  i == rows-1 {
					perimeter = perimeter + 1
					
				}
				if j == 0 {
					perimeter = perimeter + 1
				}
				
				if j == cols-1 {
					perimeter = perimeter + 1
				}
				if j < cols-1 && grid[i][j+1] == 0 {
					perimeter = perimeter + 1
				}
				if i < rows-1 && grid[i+1][j] == 0 {
					perimeter = perimeter + 1
				}
				if i >= 1 && grid[i-1][j] == 0 {
					perimeter = perimeter + 1
				}
				if j >= 1 && grid[i][j-1] == 0 {
					perimeter = perimeter + 1
				}
			}
		}
	}
	return perimeter
}

func main() {

}
