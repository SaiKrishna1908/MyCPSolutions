import java.util.*;


class ListNode {
    int data;
    ListNode next;
    ListNode random;

    ListNode (int data) {
        this.data = data;
        this.next = null;
        this.random = null;
    }
}

public class CloneListWithRandomPointer {
    ListNode cloneTheLinkedList(ListNode head) {
		ListNode temp = head;
		// key- node, value- new Node
		Map<ListNode, ListNode> map = new HashMap<>();
		
		while(temp != null) {
			map.put(temp, new ListNode(temp.data));
			temp = temp.next;
		}
		
		temp = head;
		ListNode newHead = map.get(temp);
		ListNode temp2 = newHead;
		
		while(temp != null) {
			temp2.next = map.get(temp.next);
			temp2.random = map.get(temp.random);
			temp = temp.next;
			temp2 = temp2.next;
		}
		
		return newHead;
	}
}
