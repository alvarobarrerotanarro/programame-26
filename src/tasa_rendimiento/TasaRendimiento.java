package tasa_rendimiento;

import java.util.*;

public class TasaRendimiento {
	private static Scanner in;

	public void casoPrueba() {
		int a = in.nextInt();
		double b = in.nextDouble();
		System.out.printf("%d\n", (int) (Math.round(a * b / 100)));
	}

	public static void main(String args[]) {
		in = new Scanner(System.in);
		TasaRendimiento app = new TasaRendimiento();
		int n = in.nextInt();
		while (n-- > 0) {
			app.casoPrueba();
		}
	}
}
