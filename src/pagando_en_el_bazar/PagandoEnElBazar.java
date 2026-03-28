package pagando_en_el_bazar;

import java.util.*;

public class PagandoEnElBazar {
	private static Scanner in;

	public boolean casoPrueba() {
		int precioLibras = in.nextInt();
		int precioDolares = in.nextInt();
		int precioEuro = in.nextInt();

		if (precioLibras == 0 && precioDolares == 0 && precioEuro == 0) {
			return false;
		}

		int cantidadDolares = precioLibras / precioDolares;
		int cantidadEuros = 0;
		int libras = 0;
		int restoLibras = 0;
		boolean pagado = false;

		while (!pagado && cantidadDolares <= 10000) {
			libras = cantidadDolares * precioDolares;
			restoLibras = libras - precioLibras;

			if (restoLibras >= 0 && restoLibras % precioEuro == 0) {
				pagado = true;
				cantidadEuros = restoLibras / precioEuro;
			} else {
				cantidadDolares++;
			}
		}
		
		System.out.printf("%d %d\n", cantidadDolares, cantidadEuros);

		return true;
	}

	public static void main(String args[]) {
		in = new Scanner(System.in);
		PagandoEnElBazar app = new PagandoEnElBazar();
		while (app.casoPrueba())
			;
	}
}
