import java.util.ArrayList;
import java.util.Scanner;
import java.util.Collections;

import java.util.Random;

public final class PairOfTopics {
  public static void main(String[] args) {
 
    Scanner inputUser = new Scanner(System.in);
    Integer n = inputUser.nextInt();
    
    ArrayList<Long> A = new ArrayList<Long>(); 
    ArrayList<Long> B = new ArrayList<Long>(); 

    ArrayList<Long> diff = new ArrayList<Long>(); 


    for (int i=0; i< n; ++i) {
      A.add(inputUser.nextLong());
    }

    for (int i=0; i< n; ++i) {
      B.add(inputUser.nextLong());
    }

    for (int i=0; i< n; ++i) {
      diff.add(A.get(i) - B.get(i));
    }

    Collections.sort(diff);

    Integer i = 0;
    Integer j = n-1;
    Long total = 0L;
    while (i<j) {
      if ((diff.get(i) + diff.get(j)) > 0) {
        total += j -i;
        --j;
      }
      else {
        ++i;  
      }
    }
    System.out.println(total);

  }
}
