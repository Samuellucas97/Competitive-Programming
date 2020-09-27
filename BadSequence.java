import java.util.Scanner;
import java.util.Stack;

public final class BadSequence {
    public static void main(String[] args) {

        Scanner inputUser = new Scanner(System.in);
        Integer n = inputUser.nextInt();

        String expression = inputUser.next();
           
        if (n % 2 != 0) { 
            System.out.println("No");
        }
        else {

            Stack<Character> expressionStack = new Stack<>();
            Integer numberOfErros = 0;

            for (Character i : expression.toCharArray()) {
                if ( i == '(') {
                    expressionStack.push(i);
                }
                else {
                    if (expressionStack.size() == 0 || expressionStack.peek() != '(' ) {
                        ++numberOfErros;

                        if (numberOfErros > 1) {
                            break;
                        }
                    }
                    else {
                        expressionStack.pop();
                    }
                }
            }


            if ( numberOfErros > 1 || expressionStack.size() > 1) {    
                System.out.println("No");
            }
            else {
                System.out.println("Yes");
            }
        }
    }
}
