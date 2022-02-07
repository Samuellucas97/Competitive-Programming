import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;

class Books  {
  public static void main(String[] args) {
    Scanner inputUser = new Scanner(System.in);
    Integer numberOfBooks = inputUser.nextInt();
    Long freeTime = inputUser.nextLong();
    
    Integer maxNumberOfBooksRead = 0;
    Long actualTimeUsed = 0L;
    Integer actualNumberOfBooksRead = 0;
    
    Queue<Integer> timeByBook = new LinkedList<Integer>();
    
    Integer beforeTimeBook = 0; 
    Integer timeActualBook = 0; 

    for(int i=0; i < numberOfBooks; ++i) {

      timeActualBook =  inputUser.nextInt();
        
      actualTimeUsed += timeActualBook;
      timeByBook.add(timeActualBook);
      ++actualNumberOfBooksRead;
      
      while ( actualTimeUsed > freeTime ) {
          beforeTimeBook = timeByBook.remove();
          actualTimeUsed -= beforeTimeBook;
          --actualNumberOfBooksRead;
      }
      
      if (actualNumberOfBooksRead > maxNumberOfBooksRead) 
          maxNumberOfBooksRead = actualNumberOfBooksRead;
    }

    System.out.println(maxNumberOfBooksRead);
  }
}
