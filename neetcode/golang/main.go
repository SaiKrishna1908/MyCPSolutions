package main

import (
	"fmt"
	"neetcode/arrays"
)

func main() {
	hasDuplicates := arrays.HasDuplicate([]int{2, 2, 3, 4, 5, 6})
	fmt.Printf("%t\n", hasDuplicates)
}
