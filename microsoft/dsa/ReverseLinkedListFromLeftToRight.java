class ListNode {
    int data;
    ListNode next;

    public ListNode(int data) {
        this.data = data;
        this.next = null;
    }
}

public class ReverseLinkedListFromLeftToRight {

    private ListNode reverse(ListNode head) {
		ListNode prev = null;
		ListNode current = head;
		
		while(current != null) {
			ListNode next = current.next;
			current.next = prev;
			prev = current;
			current = next;
		}
		
		return prev;
	}
	ListNode reverseLinkedListRange(ListNode head, int left, int right) {				
		ListNode dummy = new ListNode(-1);
		dummy.next = head;
		head = dummy;
		
		ListNode front = head;
		ListNode back = head;
		
		while(left > 1 || right > 0) {
			if (left > 1) {
				front = front.next;
				left--;
			}
			if (right > 0) {
				back = back.next;
				right--;
			}			
		}
		
		
		ListNode temp1 = front;
		ListNode temp2 = back.next;
		ListNode temp3 = front.next;
		
		back.next = null;
		
		temp1.next = reverse(temp1.next);
		
		// System.out.println(front.data);
		// System.out.println(back.data);
		
		if (temp2 != null) {
			temp3.next = temp2;
		}
		
		return head.next;
	}

    void printList(ListNode node) {

        while(node != null) {
            System.out.println(node.data+"->");
        }
    }
    public static void main(String[] args) {

        ReverseLinkedListFromLeftToRight reverseLinkedListFromLeftToRight = new ReverseLinkedListFromLeftToRight();
        ListNode listNode = new ListNode(1);
        reverseLinkedListFromLeftToRight.reverseLinkedListRange(null, 0, 0);
    }    
}