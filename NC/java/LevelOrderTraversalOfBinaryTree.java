package NC.java;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

import javax.swing.tree.TreeNode;

public class LevelOrderTraversalOfBinaryTree {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>();
        if (root == null) {
            return ans;
        }
        q.add(root);
        q.add(null);
        ans.add(new ArrayList<>());
        while (q.size() > 0) {
            TreeNode curr = q.poll();
            if (curr == null) {
                if (q.size() > 0) {
                    ans.add(new ArrayList<>());
                    q.add(null);
                }
            } else {
                ans.get(ans.size() - 1).add(curr.val);
                if (curr.left != null) {
                    q.add(curr.left);
                }
                if (curr.right != null) {
                    q.add(curr.right);
                }
            }
        }
        return ans;
    }
}
