package termostato;

import java.util.*;

public class Termostato {
	private static Scanner in;

	public boolean casoPrueba() {
		int n = in.nextInt();
		int e = in.nextInt();
		int a = in.nextInt();
		int actual;
		int minutos = 0;
		boolean encendido = false;

		if (n == 0 && e == 0 && a == 0) {
			return false;
		}

		for (int i = 0; i < n; i++) {
			actual = in.nextInt();

			if (encendido && actual >= a) {
				encendido = false;
			} else if (encendido || actual < e) {
				minutos++;
				encendido = true;
			}
		}

		System.out.printf("%d\n", minutos);

		return true;
	}

	public static void main(String args[]) {
		in = new Scanner(System.in);
		Termostato app = new Termostato();
		while (app.casoPrueba())
			;
	}
}
