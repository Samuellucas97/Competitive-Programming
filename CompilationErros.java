import java.util.Scanner;
import java.util.Map;
import java.util.ArrayList;
import java.util.HashMap;

public final class CompilationErros  {
  public static void main(String[] args) {
    Scanner inputUser = new Scanner(System.in);

    Integer n = inputUser.nextInt();
    Map<Long, Long> mapFirstLine = new HashMap<Long, Long>(); 
    Map<Long, Long> mapSecondLine = new HashMap<Long, Long>(); 
    Map<Long, Long> mapThirdLine = new HashMap<Long, Long>(); 
  
    Long newKey = 0L;
    for (int i =0; i < n; ++i) {
      newKey = inputUser.nextLong();
      
      if ( !mapFirstLine.containsKey(newKey) ) {
          mapFirstLine.put(newKey, 1L);
      } 
      else {
          mapFirstLine.put(newKey, mapFirstLine.get(newKey)+1);
      }  
    }
      
    for (int i =0; i < n-1; ++i) {
      newKey = inputUser.nextLong();
      
      if ( !mapSecondLine.containsKey(newKey) ) {
          mapSecondLine.put(newKey, 1L);
      } 
      else {
          mapSecondLine.put(newKey, mapSecondLine.get(newKey)+1);
      }  
    }

    for (int i =0; i < n-2; ++i) {
      newKey = inputUser.nextLong();
      
      if ( !mapThirdLine.containsKey(newKey) ) {
          mapThirdLine.put(newKey, 1L);
      } 
      else {
          mapThirdLine.put(newKey, mapThirdLine.get(newKey)+1);
      }  
    }

    ArrayList<Long> a = new ArrayList<>();
 
    for (Map.Entry<Long,Long> entry : mapFirstLine.entrySet() ) {
      if ( !mapSecondLine.containsKey(entry.getKey() ) ) {
        a.add(entry.getKey());
        break;
      } 
      else {
        if ( entry.getValue() > mapSecondLine.get(entry.getKey())  ) {
            a.add(entry.getKey());
            break;
        } 
      }
    }  



    for (Map.Entry<Long,Long> entry : mapSecondLine.entrySet() ) {
      if ( !mapThirdLine.containsKey(entry.getKey() ) ) {
        a.add(entry.getKey());
        break;
      } 
      else {
        if ( entry.getValue() > mapThirdLine.get(entry.getKey())  ) {
          a.add(entry.getKey());
            break;
        } 
      }
    }

    System.out.println(a.get(0)+ " "+ a.get(1));
          
  }
}
