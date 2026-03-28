package juego_de_la_vida;

import java.util.*;

public class JuegoDeLaVida {
	private static Scanner in;

	public void imprimirTablero(char tablero[][]) {
		for (int i = 0; i < tablero.length; i++) {
			for (int j = 0; j < tablero[0].length; j++) {
				System.out.print(tablero[i][j]);
			}
			System.out.println();
		}
	}

	public char[][] rellenarTablero(int filas, int columnas) {
		char tablero[][] = new char[filas][columnas];

		String filaActual;
		for (int i = 0; i < filas; i++) {
			filaActual = in.nextLine();
			for (int j = 0; j < columnas; j++) {
				tablero[i][j] = filaActual.charAt(j);
			}
		}
		return tablero;
	}

	public char[][] copiarTablero(char tablero[][]) {
		int filas = tablero.length;
		int columnas = tablero[0].length;
		char nuevoTablero[][] = new char[filas][columnas];

		for (int i = 0; i < filas; i++) {
			for (int j = 0; j < columnas; j++) {
				nuevoTablero[i][j] = tablero[i][j];
			}
		}

		return nuevoTablero;
	}

	/**
	 * Permite contar el numero de celdas vivas en la pos fila y columna.
	 */
	public int contarVivas(char tablero[][], int fila, int columna) {
		int numFilas = tablero.length;
		int numColumnas = tablero[0].length;
		int contador = 0;

		int filaActual, columnaActual;

		// Fila anterior de forma segura
		if (fila - 1 < 0) {
			filaActual = numFilas - 1;
		} else {
			filaActual = fila - 1;
		}

		/*
		 * Incrementamos fila y columna actual de forma segura (modulo) tres veces
		 * porque 3 x 3 genera una regilla de 9 espacios.
		 */

		for (int i = 0; i < 3; i++) {

			// Por cada fila hay que volver a resetear la columna
			if (columna - 1 < 0) {
				columnaActual = numColumnas - 1;
			} else {
				columnaActual = columna - 1;
			}

			for (int j = 0; j < 3; j++) {

				// La pos central claramente no hay que contarla.
				if ((filaActual != fila || columnaActual != columna) && tablero[filaActual][columnaActual] == 'O') {
					contador++;
				}

				columnaActual = (columnaActual + 1) % numColumnas;
			}

			filaActual = (filaActual + 1) % numFilas;
		}

		return contador;
	}

	/**
	 * Crea el siguiente tablero del juego de la vida.
	 */
	public char[][] ciclo(char tablero[][]) {
		char nuevoTablero[][] = copiarTablero(tablero);
		int celdasVivas;

		for (int i = 0; i < nuevoTablero.length; i++) {
			for (int j = 0; j < nuevoTablero[i].length; j++) {
				celdasVivas = contarVivas(tablero, i, j);

				if (nuevoTablero[i][j] == '.') {
					// La celda esta muerta

					if (celdasVivas == 3) {
						nuevoTablero[i][j] = 'O';
					}

				} else {
					// La celda esta viva

					if (celdasVivas < 2) {
						nuevoTablero[i][j] = '.';
					} else if (celdasVivas > 3) {
						nuevoTablero[i][j] = '.';
					}

				}

			}
		}

		return nuevoTablero;
	}

	public boolean casoPrueba() {
		if (!in.hasNext()) {
			return false;
		}

		int filas = in.nextInt();
		int columnas = in.nextInt();
		int ciclos = in.nextInt();
		in.nextLine();

		char tablero[][] = rellenarTablero(filas, columnas);

		for (int i = 0; i < ciclos; i++) {
			tablero = ciclo(tablero);
		}

		imprimirTablero(tablero);
		System.out.println("===");

		return true;
	}

	public static void main(String args[]) {
		in = new Scanner(System.in);
		JuegoDeLaVida app = new JuegoDeLaVida();
		while (app.casoPrueba())
			;
	}
}
