import java.util.ArrayList;
import java.util.Scanner;

class MaximalContinuousRest {
  public static void main(String[] args) {
    Scanner inputUser = new Scanner(System.in);
    Integer numberOfTest = inputUser.nextInt();
    ArrayList<Integer> a = new ArrayList<Integer>();  

    for (int i=0; i< numberOfTest; ++i) {
      a.add(inputUser.nextInt());
    }

    Boolean quadrado = false;
    Boolean triangulo = true;
    Integer numberOTriangulos = 0;
    Integer totalNumber = 0;
    Integer actualNumber = 0;

    for (int i=0; i< numberOfTest; ++i) {  
      
      if (quadrado == false) {
        if (a.get(i) == 1) {
          actualNumber += 1;
          quadrado = true;
          
          if (triangulo == true)
            numberOTriangulos+= 1;
        }
      }
      else {
        if (a.get(i) == 0 ) {
          actualNumber = 0;
          quadrado = false;
          triangulo = false;
        }
        else {
          actualNumber += 1;

          if (triangulo == true)
            numberOTriangulos+= 1;
        }
      }

      if ( actualNumber > totalNumber) {
        totalNumber = actualNumber;
      }
     }

    if (quadrado == true && a.get(0) == 1)
      actualNumber += numberOTriangulos;
    
    if (actualNumber > totalNumber) 
      totalNumber = actualNumber;
    
    System.out.println(totalNumber);
  }
}
