import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;

class RegistrationSystem {
  public static void main(String[] args) {

    Scanner inputUser = new Scanner(System.in);
    Integer n = inputUser.nextInt();

    Map<String, Integer> database = new HashMap<String, Integer>();

    for (int i= 0; i<n; ++i) {
      String user = inputUser.next();
      if (database.containsKey(user)) {
        System.out.println(user+database.get(user));
        database.put(user, database.get(user) + 1);
      }
      else {
        database.put(user, 1);
        System.out.println("OK");
      }
    }
  }
}
