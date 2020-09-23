import java.util.ArrayList;
import java.util.Scanner;
import java.util.Collections;

public final class RemoveSmallest {
  public static void main(String[] args) {
    Scanner inputUser = new Scanner(System.in);
    Integer numberOfTest = inputUser.nextInt();

    Boolean flagLoopActive = true;
    
    for (int i=0; i< numberOfTest; ++i) {
      Integer n = inputUser.nextInt();
      ArrayList<Integer> a = new ArrayList<Integer>();
      
      for (int j=0; j<n; ++j) {
        a.add(inputUser.nextInt());
      }

      Collections.sort(a);
      
      flagLoopActive = true;

      while (flagLoopActive && a.size() > 1) {
        if (Math.abs( a.get(0) - a.get(1)) == 0) {
          a.remove(0);
        }
        else if (Math.abs( a.get(0) - a.get(1)) == 1) {
          if (a.get(0) > a.get(1) )
            a.remove(1);
          else
            a.remove(0);
        }
        else {
          flagLoopActive = false;
        }
      }

      if (flagLoopActive) 
        System.out.println("YES");
      else
        System.out.println("NO");
      
    }
  }
}
