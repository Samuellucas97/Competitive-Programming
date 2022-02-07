import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.Collections;

import java.util.Random;

public final class TwoTeamsComposing {
  public static void main(String[] args) {
 
    Scanner inputUser = new Scanner(System.in);
    Long numberOfTestCase = inputUser.nextLong();
    // Long numberOfTestCase = 5L;

    for(int j=0; j<numberOfTestCase; ++j){  
        Integer n = inputUser.nextInt();
        // Integer n = new Random().nextInt((10 - 1) + 1)+1;
        Long newKey = -1L;
        Map<Long, Long> map = new HashMap<>();   

        // System.out.print("[ ");
        for (int i=0; i< n; ++i) {
            newKey = inputUser.nextLong();
            // newKey = (long) new Random().nextInt((9999 - 9990) + 1)+9990;                                              
        // System.out.print(newKey +" ");

            if ( !map.containsKey(newKey) ) {
                map.put(newKey, 1L);
            } 
            else {
                map.put(newKey, map.get(newKey)+1);
            }
        }
        // System.out.println("]");

        Long keySelected = Collections.max(map.entrySet(), Map.Entry.comparingByValue()).getKey();      
        Long maxValue = map.get(keySelected);    

        Long total = 0L;

        for (Map.Entry<Long,Long> entry : map.entrySet() ) {
            if (entry.getKey() !=  keySelected && total < maxValue) {
                // total += Math.min( (maxValue -total), entry.getValue());
                ++total;
            }

        }  

        if ( (maxValue-total) >= 2) {
            total +=1;
        }
        System.out.println(total);
    }
  }
}
