import java.util.Scanner;
public class Main{
 	public static void main(String[] args){
      Scanner a = new Scanner(System.in);
      String b = a.next();
      char c[] = b.toCharArray();
      int count=0;
      
      for(int i=0; i<3; i++){
       	if(c[i] == '1'){
         	 count++;
         
        }
        
      } 
      System.out.println(count);
      a.close();
      
    }
}