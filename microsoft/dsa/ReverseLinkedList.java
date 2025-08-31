class ListNode {
    int data;
    ListNode next;

    public ListNode(int data) {
        this.data = data;
        this.next = null;
    }
}

public class ReverseLinkedList {

    ListNode reverseLinkedList(ListNode head) {

        ListNode prev = null;
        ListNode current = head;

        if (head == null || head.next == null) {
            return head;
        }

        while (current != null) {
            ListNode next = current.next;
            current.next = prev;
            prev = current;
            current = next;                        
        }

        return prev;

    }

    void printList(ListNode node) {

        while(node != null) {
            System.out.println(node.data+"->");
        }
    }
    public static void main(String[] args) {

        ReverseLinkedList reverseLinkedList = new ReverseLinkedList();
        ListNode head1 = new ListNode(1);
        head1.next = new ListNode(2);
        head1.next.next = new ListNode(3);
        head1.next.next.next = new ListNode(4);
        head1.next.next.next.next = new ListNode(5);
        
        System.out.println("Original list 1:");
        reverseLinkedList.printList(head1);
        
        ListNode reversed1 = reverseLinkedList.reverseLinkedList(head1);
        
        System.out.println("Reversed list 1:");
        reverseLinkedList.printList(reversed1);
        System.out.println();
    }    
}