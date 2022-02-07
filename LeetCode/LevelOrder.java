import java.io.*;
import java.util.*;

import static java.lang.System.out;


public class LevelOrder {
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
						
		out.println(levelOrder(t1));
		
		TreeNode t2 = null;
		out.println(levelOrder(t2));
		
		TreeNode t3 = new TreeNode(1);
		out.println(levelOrder(t3));
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



    public static List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> finalList = new ArrayList<>();
		
		if (root != null) {
			Queue<TreeNode> q = new LinkedList<>();
			q.add(root);
			
			
			TreeNode auxNode = new TreeNode();
			int size;
			while (!q.isEmpty()) {
				List<Integer> auxList = new ArrayList<>();
				size = q.size();
				
				for(int i=0; i<size; ++i) {
					auxNode = q.poll();
					if (auxNode != null) {
						auxList.add(auxNode.val);
					
						if (auxNode.left != null) q.add(auxNode.left);
						if (auxNode.right != null) q.add(auxNode.right);
					}
				}
				
				finalList.add(auxList);
			
			}
		}
        
        return finalList;
    }
}
