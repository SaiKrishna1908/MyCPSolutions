package main

type node struct {
	key, value int
	prev, next *node
}

type LRUCache struct {
	capacity int
	cache    map[int]*node
	head     *node
	tail     *node
}

type Cache interface {
	Get(key int) int
	Put(key int, value int)
}

func NewLRUCache(capacity int) *LRUCache {
	h, t := &node{}, &node{}
	h.next = t
	t.prev = h

	return &LRUCache{
		capacity: capacity,
		cache:    make(map[int]*node),
		head:     h,
		tail:     t,
	}
}

func (c *LRUCache) Get(key int) int {
	n, ok := c.cache[key]
	if !ok {
		return -1
	}

	return n.value
}

// [-1,2,3,4,-1]
// [-1,4,2,3,-1]
// [-1,3,4,2,-1]
func (c *LRUCache) addAfterHead(n *node) {
	n.prev = c.head
	n.next = c.head.next
	c.head.next.prev = n
	c.head.next = n
}

func (c *LRUCache) remove(n *node) {
	n.prev.next = n.next
	n.next.prev = n.prev
	n.prev = nil
	n.next = nil
}
