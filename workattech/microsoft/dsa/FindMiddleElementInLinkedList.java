class ListNode {
    int data;
    ListNode next;
    
    ListNode(int data) {
        this.data = data;
        this.next = null;
    }
}

public class FindMiddleElementInLinkedList {

    int getMiddleElementOfLinkedListByFastPointer(ListNode listNode) {
        if (listNode == null) {
            return listNode.data;
        }

        ListNode fast = listNode;
        ListNode slow = listNode;

        while(fast != null && fast.next != null) {
            fast = fast.next.next;
            if (fast == null) {
                break;
            }
            slow = slow.next;
        }

        return slow.data;
    }
    
    int getMiddleElementOfLinkedList (ListNode list) {
		if (list.next == null) {
			return list.data;
		}
	    int length = 0;
		ListNode head = list;
		
		while(head != null) {
			head = head.next;
			length++;
		}								
		
		int middle = length/2;
		head = list;
		
        if (length%2 == 0) {
            middle-=1;
        }

		for(int i=0;i<middle;i++) {
			head = head.next;
		}
		
		return head.data;
	}

    ListNode createList(int[] arr) {
        if (arr.length == 0) return null;
        
        ListNode head = new ListNode(arr[0]);
        ListNode current = head;
        
        for (int i = 1; i < arr.length; i++) {
            current.next = new ListNode(arr[i]);
            current = current.next;
        }
        
        return head;
    }

    void printList(ListNode head) {
        ListNode temp = head;
        while (temp != null) {
            System.out.print(temp.data);
            if (temp.next != null) {
                System.out.print(" -> ");
            }
            temp = temp.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        FindMiddleElementInLinkedList solution = new FindMiddleElementInLinkedList();
        
        // Test case 1: Odd number of elements (1 -> 2 -> 3 -> 4 -> 5)
        int[] arr1 = {1, 2, 3, 4, 5};
        ListNode list1 = solution.createList(arr1);
        System.out.println("Test case 1 - Odd length (5 elements):");
        solution.printList(list1);
        System.out.println("Middle element: " + solution.getMiddleElementOfLinkedListByFastPointer(list1));
        System.out.println("Expected: 3\n");
        
        // Test case 2: Even number of elements (1 -> 2 -> 3 -> 4)
        int[] arr2 = {1, 2, 3, 4};
        ListNode list2 = solution.createList(arr2);
        System.out.println("Test case 2 - Even length (4 elements):");
        solution.printList(list2);
        System.out.println("Middle element: " + solution.getMiddleElementOfLinkedListByFastPointer(list2));
        System.out.println("Expected: 3\n");
        
        // Test case 3: Single element
        int[] arr3 = {42};
        ListNode list3 = solution.createList(arr3);
        System.out.println("Test case 3 - Single element:");
        solution.printList(list3);
        System.out.println("Middle element: " + solution.getMiddleElementOfLinkedListByFastPointer(list3));
        System.out.println("Expected: 42\n");
        
        // Test case 4: Two elements
        int[] arr4 = {10, 20};
        ListNode list4 = solution.createList(arr4);
        System.out.println("Test case 4 - Two elements:");
        solution.printList(list4);
        System.out.println("Middle element: " + solution.getMiddleElementOfLinkedListByFastPointer(list4));
        System.out.println("Expected: 20\n");
        
        // Test case 5: Larger odd list
        int[] arr5 = {1, 2, 3, 4, 5, 6, 7};
        ListNode list5 = solution.createList(arr5);
        System.out.println("Test case 5 - Larger odd length (7 elements):");
        solution.printList(list5);
        System.out.println("Middle element: " + solution.getMiddleElementOfLinkedListByFastPointer(list5));
        System.out.println("Expected: 4\n");
        
        // Test case 6: Larger even list
        int[] arr6 = {1, 2, 3, 4, 5, 6};
        ListNode list6 = solution.createList(arr6);
        System.out.println("Test case 6 - Larger even length (6 elements):");
        solution.printList(list6);
        System.out.println("Middle element: " + solution.getMiddleElementOfLinkedListByFastPointer(list6));
        System.out.println("Expected: 4\n");
    }
}
