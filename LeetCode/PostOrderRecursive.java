import java.io.*;
import java.util.*;

import static java.lang.System.out;


public class PostOrderRecursive {
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
						
		out.println(postOrderTraversal(t1));
		
		TreeNode t2 = null;
		out.println(postOrderTraversal(t2));
		
		TreeNode t3 = new TreeNode(1);
		out.println(postOrderTraversal(t3));
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

    public static List<Integer> postOrderTraversal(TreeNode root) {
		ArrayList<Integer> s = new ArrayList<>();
		
		if (root != null) {
			s.addAll(postOrderTraversal(root.left));
			s.addAll(postOrderTraversal(root.right));
			s.add(root.val);
		}
	
		return s;
    }
    
}
