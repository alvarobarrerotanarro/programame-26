package ballet;

import java.util.*;

public class Ballet {
	private static Scanner in;

	public boolean casoPrueba() {
		int n = in.nextInt();
		int actual, reciproca, siguiente;
		boolean imposible = false;

		if (n == 0) {
			return false;
		}

		int bailarinas[] = new int[n];
		for (int i = 0; i < n; i++) {
			bailarinas[i] = in.nextInt();
		}

		// Intercambios
		for (int i = 0; !imposible && i < n / 2 + 1; i++) {
			actual = bailarinas[i];
			reciproca = bailarinas[n - i - 1];
			siguiente = bailarinas[i + 1];

			if (actual > siguiente) {

				if (reciproca > siguiente) {
					imposible = true;
				} else {
					bailarinas[i] = reciproca;
					bailarinas[n - i - 1] = actual;
				}

			}
		}

		// Si no encontramos situacion imposible, verificamos si esta ordenado.
		if (!imposible) {
			for (int i = 1; !imposible && i < n; i++) {
				if (bailarinas[i - 1] > bailarinas[i]) {
					imposible = true;
				}
			}
		}

		System.out.println(imposible ? "NO" : "SI");

		return true;
	}

	public static void main(String args[]) {
		in = new Scanner(System.in);
		Ballet sp = new Ballet();
		while (sp.casoPrueba())
			;
	}
}
