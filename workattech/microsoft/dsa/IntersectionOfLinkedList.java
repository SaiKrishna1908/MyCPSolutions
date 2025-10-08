class ListNode {
	int data;
	ListNode next;

	ListNode(int data) {
		this.data = data;
		this.next = null;
	}
}

class IntersectionOfLinkedList {
	ListNode getIntersectionNode(ListNode A, ListNode B) {
		ListNode tempA = A;
        ListNode tempB = B;
		int lenA = 0;
		int lenB = 0;
		
		while(tempA.next != null) {
			tempA = tempA.next;
			lenA++;
		}
		
		while(tempB.next != null) {
			tempB = tempB.next;
			lenB++;
		}
		
		
		int diff = Math.abs(lenA - lenB);

        System.out.println("Difference is " + diff);
        tempA = A;
        tempB = B;
		
		if (lenA > lenB) {
			while(diff-->0) {
				tempA = tempA.next;
			}
		} else {
			while(diff-->0) {
				tempB = tempB.next;
			}
		}
		
		while(tempA != null && tempB != null) {
            if (tempA == tempB) {
                return tempA;
            }

            tempA = tempA.next;
            tempB = tempB.next;
        }
		
		return null;
	}

    public static void main(String[] args) {
    IntersectionOfLinkedList solution = new IntersectionOfLinkedList();
    
    // Create intersection node
    ListNode intersection = new ListNode(8);
    intersection.next = new ListNode(4);
    intersection.next.next = new ListNode(5);
    
    // Create first linked list: 4 -> 1 -> 8 -> 4 -> 5
    ListNode listA = new ListNode(4);
    listA.next = new ListNode(1);
    listA.next.next = intersection;
    
    // Create second linked list: 5 -> 6 -> 1 -> 8 -> 4 -> 5
    ListNode listB = new ListNode(5);
    listB.next = new ListNode(6);
    listB.next.next = new ListNode(1);
    listB.next.next.next = intersection;
    
    // Find intersection
    ListNode result = solution.getIntersectionNode(listA, listB);
    
    if (result != null) {
        System.out.println("Intersection found at node with data: " + result.data);
    } else {
        System.out.println("No intersection found");
    }
    
    // Test case with no intersection
    ListNode listC = new ListNode(2);
    listC.next = new ListNode(3);
    
    ListNode listD = new ListNode(1);
    listD.next = new ListNode(4);
    
    ListNode result2 = solution.getIntersectionNode(listC, listD);
    
    if (result2 != null) {
        System.out.println("Intersection found at node with data: " + result2.data);
    } else {
        System.out.println("No intersection found");
    }
}
}