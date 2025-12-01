package NC.java;

import javax.swing.tree.TreeNode;

public class InvertABinaryTree {
    public TreeNode invertTree(TreeNode root) {
        if (root == null) {
            return null;
        }
        TreeNode right = invertTree(root.left);
        TreeNode left = invertTree(root.right);

        root.right = right;
        root.left = left;

        return root;
    }

}
