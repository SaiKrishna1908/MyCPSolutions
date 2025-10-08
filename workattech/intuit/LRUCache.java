import java.util.HashMap;
import java.util.Map;

public class LRUCache {

    private static class Node {
        int key, value;
        Node prev, next;
        Node(int k, int v) {key = k; value = v;}
    }

    private final int capacity;
    private final Map<Integer, Node> map = new HashMap<>();
    private final Node head = new Node(-1, -1);    
    private final Node tail = new Node(-1, -1);


    public LRUCache(int capacity) {
        this.capacity = capacity;
        head.next = tail;
        tail.prev = head;
    }
    
    public int get(int key) {
        // get the node
        Node n = map.get(key);
        if (n == null) return -1;
        moveToHead(n, true);
        return n.value;
    }
    
    public void put(int key, int value) {
        if (capacity <= 0) return;
        Node n = map.get(key);

        if (n != null) {
            n.value = value;
            moveToHead(n, true);
            return;
        }
        Node nn = new Node(key, value);
        map.put(key, nn);
        moveToHead(nn, false);

        if (map.size() > capacity) {
            Node lru = popTail();
            map.remove(lru.key);
        }
    }

    private void moveToHead(Node n, boolean isExisting) {
        if (isExisting) {
            remove(n);
        } 
        addAfterHead(n);
    }

    // head here is sentinel
    private void addAfterHead(Node n) {
        n.next = head.next;
        n.prev = head;
        head.next.prev = n;
        head.next = n;
    }

    private void remove(Node n) {
        n.prev.next = n.next;
        n.next.prev = n.prev;
    }

    private Node popTail() {
        Node leastUsed = tail.prev;
        remove(leastUsed);
        return leastUsed;
    }

    private void printCache() {
        Node current = head.next;

        while(current.next != null) {
            System.out.print(current.key+" ");
            current = current.next;
        }
        System.out.println(); 
    }

    // [4,3,1,2]
    public static void main(String[] args) {
        LRUCache cache = new LRUCache(10);
        cache.put(1, 1);
        cache.put(2, 2);
        cache.put(3, 3);
        cache.put(1, 1);
        cache.put(3, 5);
        cache.put(4, 4);

        System.out.println(cache.get(3));
        System.out.println(cache.get(5));        

        cache.printCache();
    }
}