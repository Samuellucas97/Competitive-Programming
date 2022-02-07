import java.util.Scanner;
import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;
import java.util.Collections;
import java.util.Comparator;

class SubstringSort  {
  public static void main(String[] args) {
    Scanner inputUser = new Scanner(System.in);

    Integer n = inputUser.nextInt();    
    ArrayList<String> strings = new ArrayList<>();

    for (int i = 0; i < n; ++i) {
        strings.add(inputUser.next());
    }

    Collections.sort(strings, Comparator.comparing(String::length));
    // System.out.println(strings);
    
    String actualString = strings.get(0);
    Queue<String> queue = new LinkedList<>(); 
    queue.add(actualString);

    Boolean resp = true;

    for (int i = 1; i < n; ++i) {
        if ( strings.get(i).contains(actualString) ) {
            queue.add(strings.get(i));
            actualString = strings.get(i);
        }
        else {
            resp = false;
            break;
        }
    }
    if (resp == false) {
        System.out.println("NO");
    }
    else {
        System.out.println("YES");
        
        while (!queue.isEmpty()) {
            System.out.println(queue.remove());
        }
    }
  }
}
