package cadenas;

import java.util.Scanner;

public class Cadenas {
	private static Scanner in;

	public void casoPrueba() {
		int n = in.nextInt();
		System.out.printf("%d %d\n", (n + 1) / 2, n / 2);
	}

	public static void main(String args[]) {
		in = new Scanner(System.in);
		Cadenas app = new Cadenas();
		int n = in.nextInt();
		while (n-- > 0) {
			app.casoPrueba();
		}
	}
}