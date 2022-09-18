import java.io.*;
import java.util.*;

import static java.lang.System.out;


public class InOrderIterative {
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
        
        
        Stack<TreeNode> stk = new Stack<>();  
		List<Integer> finalList = new ArrayList<>();
		
		
		if( root != null) {
			stk.push(root);
			
			TreeNode aux = new TreeNode();	
			while(!stk.empty()) {
				aux = stk.pop();
				finalList.add(aux.val);
				if (aux.right != null) stk.push(aux.right);
				if (aux.left != null) stk.push(aux.left);
			}

		}
        
        return finalList;
    }
}
