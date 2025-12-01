package NC.java;

import java.util.Stack;

import javax.swing.tree.TreeNode;

public class SubtreeOfABinaryTree {
    private boolean areEqual(TreeNode root, TreeNode subRoot) {
        if (root == null && subRoot == null) {
            return true;
        }
        if (root == null || subRoot == null) {
            return false;
        }

        return root.val == subRoot.val && areEqual(root.left, subRoot.left) && areEqual(root.right, subRoot.right);

    }

    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        if (root == null && subRoot == null) {
            return true;
        }
        if (root == null || subRoot == null) {
            return false;
        }

        Stack<TreeNode> s = new Stack();

        s.push(root);

        while (s.size() > 0) {
            root = s.peek();
            s.pop();
            if (areEqual(root, subRoot)) {
                return true;
            }
            if (root.left != null) {
                s.push(root.left);
            }
            if (root.right != null) {
                s.push(root.right);
            }
        }

        return false;

    }
}
