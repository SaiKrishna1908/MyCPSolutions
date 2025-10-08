import java.util.*;

class ListNode {
    int data;
    ListNode next;
    
    ListNode(int data) {
        this.data = data;
        this.next = null;
    }
}

public class AddTwoNumbersAsList {
    void padZeros(ListNode first, ListNode second) {
        int size1 = 1;
        int size2 = 1;
        ListNode temp = first;
        ListNode temp2 = second;
        while(temp.next != null) {
            temp = temp.next;
            size1++;
        }		
        while (temp2.next != null) {
            temp2 = temp2.next;
            size2++;
        }
        
        if (size1 > size2) {
            for(int i=0;i<size1-size2;i++) {
                temp2.next = new ListNode(0);
                temp2 = temp2.next;
            }
        }
        
        if (size2 > size1) {
            for(int i=0;i<size2-size1;i++) {
                temp.next = new ListNode(0);
                temp = temp.next;
            }
        }
    }
    
    ListNode reverseLinkedList(ListNode head) {
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
    
    ListNode addTwoNumbers(ListNode firstList, ListNode secondList) {		
        padZeros(firstList, secondList);
        firstList = reverseLinkedList(firstList);
        secondList = reverseLinkedList(secondList);
        
        Stack<Integer> s1 = new Stack<>();
        Stack<Integer> s2 = new Stack<>();
        
        ListNode temp = firstList;
        while(temp != null) {
            s1.push(temp.data);
            temp = temp.next;
        }
        
        temp = secondList;
        while(temp != null) {
            s2.push(temp.data);
            temp = temp.next;
        }
        
        int carry = 0;
        ListNode head = null;		
        
        while(!s1.empty() && !s2.empty()) {
            int data = s1.pop() + s2.pop() + carry;
            carry = data/10;
            if (head == null) {
                head = new ListNode(data%10);		
                temp = head;
            }
            else {
                temp.next = new ListNode(data%10);
                temp = temp.next;
            }			
        }
        
        if (carry != 0) {
            temp.next = new ListNode(carry);
            carry=0;
        }
        
        return head;
    }
    
    // Helper method to create a linked list from array
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
    
    // Helper method to print the linked list
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
        AddTwoNumbersAsList solution = new AddTwoNumbersAsList();
        
        // Test case 1: 342 + 465 = 807
        // List1: 3 -> 4 -> 2
        // List2: 4 -> 6 -> 5
        // Result: 8 -> 0 -> 7
        int[] arr1 = {3, 4, 2};
        int[] arr2 = {4, 6, 5};
        ListNode list1 = solution.createList(arr1);
        ListNode list2 = solution.createList(arr2);
        
        System.out.println("Test case 1:");
        System.out.print("First number: ");
        solution.printList(list1);
        System.out.print("Second number: ");
        solution.printList(list2);
        
        ListNode result1 = solution.addTwoNumbers(list1, list2);
        System.out.print("Sum: ");
        solution.printList(result1);
        System.out.println("Expected: 8 -> 0 -> 7\n");
        
        // Test case 2: 999 + 1 = 1000
        // List1: 9 -> 9 -> 9
        // List2: 1
        // Result: 1 -> 0 -> 0 -> 0
        int[] arr3 = {9, 9, 9};
        int[] arr4 = {1};
        ListNode list3 = solution.createList(arr3);
        ListNode list4 = solution.createList(arr4);
        
        System.out.println("Test case 2:");
        System.out.print("First number: ");
        solution.printList(list3);
        System.out.print("Second number: ");
        solution.printList(list4);
        
        ListNode result2 = solution.addTwoNumbers(list3, list4);
        System.out.print("Sum: ");
        solution.printList(result2);
        System.out.println("Expected: 1 -> 0 -> 0 -> 0\n");
        
        // Test case 3: 123 + 456 = 579
        int[] arr5 = {1, 2, 3};
        int[] arr6 = {4, 5, 6};
        ListNode list5 = solution.createList(arr5);
        ListNode list6 = solution.createList(arr6);
        
        System.out.println("Test case 3:");
        System.out.print("First number: ");
        solution.printList(list5);
        System.out.print("Second number: ");
        solution.printList(list6);
        
        ListNode result3 = solution.addTwoNumbers(list5, list6);
        System.out.print("Sum: ");
        solution.printList(result3);
        System.out.println("Expected: 5 -> 7 -> 9");
    }
}