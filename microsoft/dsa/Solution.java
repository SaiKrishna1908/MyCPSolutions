import java.util.*;

class ListNode {
    int data;
    ListNode next;

    ListNode(int data) {
        this.data = data;
        this.next = null;
    }
}

public class Solution {

    void printLinkedList(ListNode head) {
        System.out.println();
        ListNode temp = head;
        while (temp != null) {
            System.out.print(temp.data+" -> ");
            temp = temp.next;
        }
    }

    ListNode reverseLinkedList(ListNode head) {
        ListNode temp = head;
        ListNode prev = null;
        ListNode current = head;
        while (current != null) {
            ListNode next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }

    ListNode removeXthNodeFromEnd(ListNode head, int x) {
        ListNode newHead = reverseLinkedList(head);
        printLinkedList(newHead);
        ListNode temp = newHead;
        ListNode prev = null;
        while (x-- > 1) {
            prev = temp;
            temp = temp.next;
        }
        if (prev == null) {
            newHead = newHead.next;
        } else {
            prev.next = temp.next;
        }        
        return reverseLinkedList(newHead);
    }
    
    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test case 1: Remove 2nd node from end
        // List: 1 -> 2 -> 3 -> 4 -> 5, remove 2nd from end (node 4)
        // Expected: 1 -> 2 -> 3 -> 5
        ListNode head1 = new ListNode(1);
        head1.next = new ListNode(2);
        head1.next.next = new ListNode(3);
        head1.next.next.next = new ListNode(4);
        head1.next.next.next.next = new ListNode(5);

        System.out.println("Test case 1:");
        System.out.println("Original list:");
        solution.printLinkedList(head1);

        ListNode result1 = solution.removeXthNodeFromEnd(head1, 2);
        System.out.println("After removing 2nd node from end:");
        solution.printLinkedList(result1);
        System.out.println("Expected: 1 2 3 5\n");

        // Test case 2: Remove 1st node from end (last node)
        // List: 1 -> 2 -> 3, remove 1st from end (node 3)
        // Expected: 1 -> 2
        ListNode head2 = new ListNode(1);
        head2.next = new ListNode(2);
        head2.next.next = new ListNode(3);

        System.out.println("Test case 2:");
        System.out.println("Original list:");
        solution.printLinkedList(head2);

        ListNode result2 = solution.removeXthNodeFromEnd(head2, 1);
        System.out.println("After removing 1st node from end:");
        solution.printLinkedList(result2);
        System.out.println("Expected: 1 2\n");

        // Test case 3: Remove 3rd node from end
        // List: 10 -> 20 -> 30 -> 40, remove 3rd from end (node 20)
        // Expected: 10 -> 30 -> 40
        ListNode head3 = new ListNode(10);
        head3.next = new ListNode(20);
        head3.next.next = new ListNode(30);
        head3.next.next.next = new ListNode(40);

        System.out.println("Test case 3:");
        System.out.println("Original list:");
        solution.printLinkedList(head3);

        ListNode result3 = solution.removeXthNodeFromEnd(head3, 3);
        System.out.println("After removing 3rd node from end:");
        solution.printLinkedList(result3);
        System.out.println("Expected: 10 30 40\n");

        // Test case 4: Remove from single node list
        // List: 42, remove 1st from end
        // Expected: empty list
        ListNode head4 = new ListNode(42);

        System.out.println("Test case 4:");
        System.out.println("Original list:");
        solution.printLinkedList(head4);

        ListNode result4 = solution.removeXthNodeFromEnd(head4, 1);
        System.out.println("After removing 1st node from end:");
        if (result4 == null) {
            System.out.println("List is empty");
        } else {
            solution.printLinkedList(result4);
        }
        System.out.println("Expected: empty list");
    }

}