import java.util.Scanner;

public class Palindrome {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String S = sc.nextLine();
		
		for(int i=0; i<S.length(); i++) {
			//to check inner data, use substring
			//Since we already know previous data needs symmetry value.
			if(isPalindrome(S.substring(i))) {
				System.out.println(i+S.length());
				return;
			}
		}
		System.out.println(S.length()*2);
	}
	
	//check from the first and the last by proceeding to the center.
	private static boolean isPalindrome(String str) {
		for(int i=0; i<=str.length()/2; i++) {
			if(str.charAt(i) != str.charAt(str.length()-i-1))
				return false;
		}
		return true;
	}
}
