import java.util.ArrayList;
import java.util.Scanner;
import java.util.Collections;
import java.util.Comparator;

class Main {
  public static void main(String[] args) {
    Scanner inputUser = new Scanner(System.in);
    Integer numberOfTest = inputUser.nextInt();
    ArrayList<Integer> a = new ArrayList<Integer>();  

    for (int i=0; i< numberOfTest; ++i) {
      a.add(inputUser.nextInt());
    }
    Collections.sort(a, Comparator.comparingInt(Math::abs));
    Long x = 0L;
    Long y = 0L;

    Integer i = 0;
    while (i < numberOfTest) {    
      if (i % 2 == 0) {
        x += (long) a.get(a.size()-1);
        a.remove(a.size()-1);
      }
      else {
        y += (long) a.get(0);
        a.remove(0);
      }
      ++i;
    }

    System.out.println(x*x + y*y);
  
    
  }
}
