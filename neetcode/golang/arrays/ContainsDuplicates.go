package arrays

func HasDuplicate(nums []int) bool {
	var dmap = make(map[int]int)

	for _, n := range nums {
		value, ok := dmap[n]

		if ok {
			return true
		}

		dmap[n] = value + 1
	}

	return false
}
