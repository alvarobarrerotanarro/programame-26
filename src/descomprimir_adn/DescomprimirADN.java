package descomprimir_adn;

import java.util.*;

public class DescomprimirADN {
	private static Scanner in;

	public long longitudCadena(String cadena) {
		Deque<Long> sumas = new ArrayDeque<>();
		int factor = 1;
		char ch;

		sumas.add(0L);

		for (int i = 0; i < cadena.length(); i++) {
			ch = cadena.charAt(i);

			if (Character.isAlphabetic(ch)) {
				sumas.addLast(sumas.removeLast() + 1);

			} else if (Character.isDigit(ch)) {
				factor = Integer.parseInt("" + ch);
				sumas.addLast(0L);

			} else if (ch == ']') {
				long val = sumas.removeLast() * factor;
				sumas.addLast(sumas.removeLast() + val);

			}
		}

		return sumas.getFirst();
	}

	public boolean casoPrueba() {
		if (!in.hasNext()) {
			return false;
		}

		String cadena = in.nextLine();
		System.out.println(longitudCadena(cadena));

		return true;
	}

	public static void main(String args[]) {
		in = new Scanner(System.in);
		DescomprimirADN app = new DescomprimirADN();
		while (app.casoPrueba())
			;
	}
}
