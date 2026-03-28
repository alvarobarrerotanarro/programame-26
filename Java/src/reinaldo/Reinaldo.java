package reinaldo;

import java.util.*;

public class Reinaldo {
	private static Scanner in;

	/**
	 * Devuelve un char array sin espacios del texto especificado.
	 */
	public char[] eliminarEspacios(String texto) {
		StringBuilder builder = new StringBuilder();

		char ch;
		for (int i = 0; i < texto.length(); i++) {
			ch = texto.charAt(i);
			if (!Character.isWhitespace(ch)) {
				builder.append(ch);
			}
		}

		return builder.toString().toCharArray();
	}

	public void casoPrueba() {
		int contador = 0;

		char primeraLinea[] = eliminarEspacios(in.nextLine());
		char segundaLinea[] = eliminarEspacios(in.nextLine());

		Map<Character, Integer> frecuenciaSegunda = new HashMap<>();
		Map<Character, Integer> cadaFrecuencia = new HashMap<>();

		// Frecuencia de la segunda linea
		for (int i = 0; i < segundaLinea.length; i++) {
			frecuenciaSegunda.put(segundaLinea[i], frecuenciaSegunda.getOrDefault(segundaLinea[i], 0) + 1);
		}

		// Buscamos una subcadena con la misma frecuencia.
		for (int i = 0; i <= primeraLinea.length - segundaLinea.length; i++) {
			cadaFrecuencia.clear();

			for (int j = i; j < segundaLinea.length + i; j++) {
				cadaFrecuencia.put(primeraLinea[j], cadaFrecuencia.getOrDefault(primeraLinea[j], 0) + 1);
			}

			// Comparo las palabras bajo el criterio: Misma frecuencia de todas las mismas
			// letras en cualquier orden
			if (frecuenciaSegunda.entrySet().equals(cadaFrecuencia.entrySet())) {
				contador++;
			}
		}

		System.out.println(contador);
	}

	public static void main(String args[]) {
		in = new Scanner(System.in);

		Reinaldo app = new Reinaldo();
		int n = in.nextInt();
		in.nextLine();

		for (int i = 0; i < n; i++) {
			app.casoPrueba();
		}
	}
}