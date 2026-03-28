package numeros_sin_digitos;

import java.util.*;

public class NumerosSinDigitos {
	public static Scanner in;

	/**
	 * Cuenta el numero de bolas necesarias para contar un numero en una abaco de
	 * una base determinada.
	 */
	public int contarCuentas(int num, int base) {
		int totalCuentas = 0;
		int digito;

		do {
			digito = num % base;
			num /= base;

			totalCuentas += digito;
		} while (num > 0);

		return totalCuentas;
	}

	/**
	 * Cuenta el numero de paralelas en el abaco hasta poder representar el numero
	 * en la base especificada.
	 */
	public int contarSeparadores(int num, int base) {
		int separadores = 0;
		num = Math.max(0, num - 1);

		do {
			separadores++;
			num /= base;
		} while (num > 0);

		return separadores;
	}

	public void casoPrueba() {
		String numStr = in.next();
		int num = Integer.parseInt(numStr);

		int cuentas;
		int minBase = 2;
		int minCuentas = Integer.MAX_VALUE;

		for (int j = 2; j <= 10; j++) {
			// Hay que contar el separador.
			cuentas = contarCuentas(num, j) + contarSeparadores(num, j);
			if (cuentas < minCuentas) {
				minCuentas = cuentas;
				minBase = j;
			}
		}

		System.out.println(minBase);
	}

	public static void main(String args[]) {
		in = new Scanner(System.in);
		int n = in.nextInt();
		NumerosSinDigitos app = new NumerosSinDigitos();

		while (n-- > 0)
			app.casoPrueba();
	}
}
