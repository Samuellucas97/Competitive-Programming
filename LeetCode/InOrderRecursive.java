import java.io.*;
import java.util.*;

import static java.lang.System.out;


public class InOrderRecursive {
    public static void main(String[] args) {
		TreeNode t1 = new TreeNode(1,
							null,
							new TreeNode(2,
								new TreeNode(3,
									null,
									null
								),
								null
							)
						);
						
		out.println(inorderTraversal(t1));
		
		TreeNode t2 = null;
		out.println(inorderTraversal(t2));
		
		TreeNode t3 = new TreeNode(1);
		out.println(inorderTraversal(t3));
    }
    
	static class TreeNode {
		int val;
		TreeNode left;
		TreeNode right;
		TreeNode() {}
		TreeNode(int val) { this.val = val; }
		TreeNode(int val, TreeNode left, TreeNode right) {
			this.val = val;
			this.left = left;
			this.right = right;
		}
	}

    public static List<Integer> inorderTraversal(TreeNode root) {
		ArrayList<Integer> s = new ArrayList<>();
		
		if (root != null) {
			s.addAll(inorderTraversal(root.left));
			s.add(root.val);
			s.addAll(inorderTraversal(root.right));
		}
	
		return s;
    }
}
