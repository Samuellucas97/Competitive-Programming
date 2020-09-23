import java.util.Scanner;
final class YetAnotherTwoIntegersProblem {
  public static void main(String[] args) {

    Scanner inputUser = new Scanner(System.in);
    Integer n = inputUser.nextInt();

    Integer a = 0;
    Integer b = 0;
    Integer aux = 0;
  

    for (int i= 0; i < n; ++i) {
      a = inputUser.nextInt();
      b = inputUser.nextInt();
  
      if ( b > a) {
        aux = a;
        a = b;
        b = aux;
      }


      int div = (a - b)/10;

      if ( (a-b) % 10 == 0)
        System.out.println(div);
      else
        System.out.println(div + 1);
        
    }
  }
}
