class ListNode {
    int data;
    ListNode next;

    ListNode(int data) {
        this.data = data;
        this.next = null;
    }

    ListNode(int data, ListNode prev) {
        this.data = data;
        prev.next = this;
    }
}

public class RemoveDuplicatesFromLinkedList {
    static ListNode removeDuplicates(ListNode root) {
        if (root == null || root.next == null) {
            return root;
        }

        ListNode dummyNode = new ListNode(-1);
        dummyNode.next = root;

        ListNode prev = dummyNode;
        ListNode current = root;

        while(current != null) {
            boolean isDuplicate = false;

            while(current.next != null && current.next.data == current.data) {
                isDuplicate = true;
                current=current.next;
            }

            if (isDuplicate) {
                prev.next = current.next;
            } else {
                prev = prev.next;
            }

            current = current.next;
        }

        if (dummyNode.next == null) {
            return null;
        }

        return dummyNode.next;

    }

    static void printLinkedList(ListNode head) {
        while(head != null) {
            System.out.print(head.data+ "->");
            head=head.next;
        }
    }

    public static void main(String[] args) {
        ListNode node1 = new ListNode(1);
        ListNode node2 = new ListNode(2, node1);
        ListNode node3 = new ListNode(2, node2);
        ListNode node4 = new ListNode(2, node3);
        ListNode node5 = new ListNode(3, node4);
        ListNode node6 = new ListNode(3, node5);

        printLinkedList(node1);

        System.out.println();

        node1 = removeDuplicates(node1);

        printLinkedList(node1);

    }
}