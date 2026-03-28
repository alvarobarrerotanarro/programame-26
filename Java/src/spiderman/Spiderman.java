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

	/*
	 * Me parece que hay un problema de interpretacion con el ejercicio si bien en
	 * el escenario:
	 * 
	 * 5 2 4 1 1 1
	 * 
	 * Podemos ordenar: 1 1 1 2 4
	 * 
	 * y sumar 2 + 6, que es > 5 (dos sumandos alcanzan sobrepasando el 5)
	 * 
	 * la suma que mejor se ajusta seria: 4 + 1 = 5 porque esta pegado del 5 (y da
	 * la casualidad que la misma cantidad de sumandos, de ahi la confusion)
	 */
	public static void main(String args[]) {
		in = new Scanner(System.in);
		Spiderman sp = new Spiderman();
		while (sp.casoPrueba())
			;
	}
}
