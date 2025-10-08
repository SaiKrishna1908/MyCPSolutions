
public class ReverseLinkedList {

    static class ListNode {
        int data;
        ListNode next;

        ListNode(int data) {
            this.data = data;
        }

        ListNode next(ListNode listNode) {
            this.next = listNode;
            return listNode;
        }

        ListNode next(int data) {
            this.next = new ListNode(data);
            return this.next;
        }
    }

    static ListNode reverseLinkedList(ListNode head) {
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

    public static void main(String[] args) {
        ListNode head = new ListNode(6);

        head.next(5).next(4).next(3).next(2).next(1);

        head = reverseLinkedList(head);

        ListNode temp = head;
        while(temp != null) {
            System.out.println(temp.data);
            temp = temp.next;
        }
    }
}
