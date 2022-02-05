import java.io.*;
import java.util.*;

import static java.lang.System.out;


public class PreOrderRecursive {
    public static void main(String[] args) {
		/**Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		out.println(n);*/
		
		TreeNode t1 = new TreeNode(1,
							null,
							new TreeNode(2,
								new TreeNode(3),
								null
							)
						);
		
		out.println(preorderTraversal(t1));
		
		TreeNode t2 = null;
		
		out.println(preorderTraversal(t2));
		
		TreeNode t3 = new TreeNode(1);
		
		out.println(preorderTraversal(t3));
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
    
    public static List<Integer> preorderTraversal(TreeNode root) {
			
			ArrayList<Integer> s = new ArrayList<>();
	
			if (root != null) {
				s.add(root.val);
				s.addAll(preorderTraversal(root.left));
				s.addAll(preorderTraversal(root.right));	
			}
	
			return s;
    }
}
