
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileNotFoundException;
import java.io.IOException;

class Main {
  public static String lerArquivo( String nomeDoArquivo ){
    String conteudo = new String("");

    try{
      BufferedReader buffReader = new BufferedReader(new FileReader( nomeDoArquivo ));
      String linha = new String();

      while( buffReader.ready() ){
          linha = buffReader.readLine();
          conteudo += linha + "\n";
      }
      
      buffReader.close();
      return conteudo;
    }
    catch(FileNotFoundException e){ 
      System.err.println( e.getMessage() );   
      return "";
    }  
    catch(IOException e){  
      System.err.println( e.getMessage() );
      return "";
    }
  }

  public static void main(String[] args) {
    String content = lerArquivo("values.txt");
    System.out.println(content);
    
  }
}
