import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
public final class Hotelier {
  public static void main(String[] args) {
    Scanner inputUser = new Scanner(System.in);
    Integer n = inputUser.nextInt();
    
    ArrayList<Integer> hotel = new ArrayList<>(Arrays.asList(0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
    String actual = inputUser.next();

    for (Character c: actual.toCharArray()) {
        // System.out.println(c);
        if (Character.isLetter(c) ) {
            if (c == 'L') {
                int i = 0;
                while (hotel.get(i) != 0 )
                    ++i;
                
                hotel.set(i, 1);
            }
            else {
                int i = hotel.size()-1;
                while (hotel.get(i) != 0)
                    --i;
                //1010000011
                //0110000011
                hotel.set(i, 1);
            }
        }
        else {
            hotel.set(Character.getNumericValue(c), 0);
        }
    }

    for (Integer i: hotel)
        System.out.print(i);
    
    System.out.println();
    
  }
}
