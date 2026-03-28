package spiderman;

import java.util.*;

public class Spiderman {
	private static Scanner in;

	public boolean casoPrueba() {
		int n = in.nextInt();
		int manzanas = 0;
		int saltos;

		if (n == 0) {
			return false;
		}

		int edificios[] = new int[n];
		for (int i = 0; i < n; i++) {
			edificios[i] = in.nextInt();
		}
		Arrays.sort(edificios);

		int i;
		for (i = n - 1; manzanas < n && i >= 0; i--) {
			manzanas += edificios[i];
		}

		if (manzanas < n) {
			System.out.println("IMPOSIBLE");
		} else {
			saltos = n - (i + 1);
			System.out.println(saltos);
		}

		return true;
	}

	public static void main(String args[]) {
		in = new Scanner(System.in);
		Spiderman sp = new Spiderman();
		while (sp.casoPrueba())
			;
	}
}
