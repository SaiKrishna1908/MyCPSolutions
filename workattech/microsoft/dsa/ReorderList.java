public class ReorderList {
    ListNode reverse(ListNode head) {
		ListNode prev = null;
		ListNode current = head;
		
		if (head == null || head.next == null) {
			return head;
		}
		
		while(current != null) {
			ListNode next = current.next;
			current.next = prev;
			prev = current;
			current = next;			
		}
		
		return prev;
	}
	ListNode reorderList(ListNode head) {
		
	    if (head == null || head.next == null) return head;
		
		ListNode sp = head;
		ListNode fp = head;
		
		while(fp != null && fp.next != null) {
			fp = fp.next.next;
			sp = sp.next;
		}
		
		
		ListNode temp = head;
		ListNode aux = reverse(sp.next);
		
		sp.next = null;
		
		while(temp != null && aux != null) {
			ListNode temp2 = temp.next;
			ListNode temp3 = aux.next;
			
			temp.next = aux;
			aux.next = temp2;
			
			aux = temp3;
			temp = temp2;
		}
		
		return head;
	}
}
