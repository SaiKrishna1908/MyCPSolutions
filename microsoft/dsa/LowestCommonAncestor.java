class Node {
    Node left;
    Node right;
    int data;
}

public class LowestCommonAncestor {
    Node lowestCommonAncestor (Node root, Node p, Node q) {
        if (root == null || p == root || q == root) {
            return root;
        } 

        Node left = lowestCommonAncestor(root.left, p, q);
        Node right = lowestCommonAncestor(root.right, p, q);

        if (left != null && right != null) {
            return root;
        }

        return (left == null) ? right : left;
    }
}