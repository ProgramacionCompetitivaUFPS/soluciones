/********************************************************************
 * Ejercicio: Puzzle                                                *
 * Url: https://acm.javeriana.edu.co/maratones/2015/09              *
 * Lenguaje: Java                                                   *
 * Autor: Cristhian Leonardo Leon                                   *
 * Fecha: 22-09-2015                                                *
 *******************************************************************/
import java.util.*;
import java.io.*;

public class D {

	static HashMap<String, ArrayList<String>> mapa;
	static SortedMap<String, Long> resultados = new TreeMap<String, Long>();
	static boolean ini[], ini2[];
	static String mat[][];
	static TreeSet<String> cantVariables[], cantVariables2[];
	static SortedMap<Integer, List<Integer>> c1, c2;

	public static void main(String[] args) throws IOException {

		Scanner sc = new Scanner();
		PrintWriter so = new PrintWriter(System.out);

		int a, b;

		String[] primeros;
		String[] primeros2;

		boolean flag;

		while (sc.hasNext()) {

			a = Integer.parseInt(sc.next());
			b = Integer.parseInt(sc.next());

			mapa = new HashMap<String, ArrayList<String>>();
			resultados = new TreeMap();
			cantVariables = new TreeSet[a];
			cantVariables2 = new TreeSet[b];
			mat = new String[a + 1][b + 1];

			// inicializo el vectores ini
			ini = new boolean[b];
			ini2 = new boolean[a];

			primeros = new String[b];
			primeros2 = new String[a];
			flag = true;

			int i = 0;
			Arrays.fill(ini2, true);
			while (i < a) {
				//recibo por linea y luego separo
				String linea = sc.nextLine();
				String lineav[] = linea.split(" ");

				if (flag) {
					flag = false;
					Arrays.fill(ini, true);

					cantVariables[i] = new TreeSet<>();

					for (int j = 0; j < lineav.length - 1; j++) {
						if (j == 0) {
							primeros2[i] = lineav[j];

						} else {
							if (lineav[j].equals(primeros2[i]) && ini2[i]) {
								ini2[i] = true;
							} else {
								ini2[i] = false;
							}

						}
						cantVariables2[j] = new TreeSet<>();
						cantVariables2[j].add(lineav[j]);
						primeros[j] = lineav[j];
						// agrego a la cantidad de variables la linea
						cantVariables[i].add(lineav[j]);
						// agrego a la adyacencia
						agregarAdyacencia(lineav[j], i, j);
					}

					mat[i][mat[i].length - 1] = lineav[lineav.length - 1];

				} else {

					cantVariables[i] = new TreeSet<>();
					for (int j = 0; j < lineav.length - 1; j++) {

						if (j == 0) {
							primeros2[i] = lineav[j];
						} else {
							if (lineav[j].equals(primeros2[i]) && ini2[i]) {
								ini2[i] = true;
							} else {
								ini2[i] = false;
							}

						}
						cantVariables2[j].add(lineav[j]);
						// agrego a la cantidad de variables
						cantVariables[i].add(lineav[j]);
						// agrego a la adyacencia
						agregarAdyacencia(lineav[j], i, j);

						if (lineav[j].equals(primeros[j]) && ini[j]) {
							ini[j] = true;
						} else {
							ini[j] = false;
						}

					}
					mat[i][mat[i].length - 1] = lineav[lineav.length - 1];

				}
				i++;

			}

			// EMPEZAR
			// agrego a la matriz los ultimos valores
			String scores = sc.nextLine() + " x";
			mat[mat.length - 1] = scores.split(" ");

			if (todosIguales()) {
				for (int aux = 0; aux < b; aux++) {
					resultados.put(primeros[aux],
							(Long.parseLong(mat[mat.length - 1][aux])) / a);
				}
			}

			// pos 0: 0-h , 1-v
			// pos 1:indice o -1
			int[] indicePrimeraVariable = indiceEmpezar();

			while (indicePrimeraVariable[1] != -1) {

				if (indicePrimeraVariable[0] == 0) {

					int indice = indicePrimeraVariable[1];
					String v[] = mat[indice];
					long sumaResto = 0;
					int cantidadResto = 0;
					for (int k = 0; k < v.length - 1; k++) {
						if (v[k] != null) {
							sumaResto += Long.parseLong(v[k]);
							cantidadResto++;
						}
					}

					long valorV = ((Long
							.parseLong(mat[indice][mat[indice].length - 1])) - (sumaResto))
							/ (b - cantidadResto);
					String var = cantVariables[indice].pollFirst();
					reemplazarValor(var, valorV);

				} else {

					int indice = indicePrimeraVariable[1];
					long sumaResto = 0;
					int cantidadResto = 0;
					for (int u = 0; u < mat.length - 1; u++) {
						if (mat[u][indice] != null) {
							sumaResto += Long.parseLong(mat[u][indice]);
							cantidadResto++;
						}
					}

					long valorV = ((Long.parseLong(mat[mat.length - 1][indice])) - (sumaResto))
							/ (a - cantidadResto);

					String var = cantVariables2[indice].pollFirst();
					reemplazarValor(var, valorV);
				}

				indicePrimeraVariable = indiceEmpezar();

			} // while hayan para iterar

			// imprimir respuesta

			Iterator it = resultados.entrySet().iterator();
			while (it.hasNext()) {
				Map.Entry e = (Map.Entry) it.next();
				so.println(e.getKey() + " " + e.getValue());
			}
		}
		so.flush();
	}

	private static int[] indiceEmpezar() {
		// pos 0 = 0=>horizontal 1=>vertical
		// pos 1 = -1 o indice

		int res[] = { -1, -1 };

		// el indice de donde esta el 1
		// siempre y cuando este, sino es -1
		int uno = hayVariables(0);
		if (uno != -1) {
			res[0] = 0;// horizontal
			res[1] = uno;
			return res;
		}

		int dos = hayVariables(1);
		if (dos != -1) {
			res[0] = 1;// vertical
			res[1] = dos;
			return res;
		}

		// si no es ninguno de los dos condicionales anteriores, es xq ambos son -1
		// y retorna -1
		return res;

	}

	private static boolean todosIguales() {

		boolean bnd = true;

		for (int i = 0; i < ini.length; i++) {
			if (!ini[i]) {
				bnd = false;
			}
		}

		if (bnd)
			return true;

		bnd = true;
		for (int i = 0; i < ini2.length; i++) {
			if (!ini2[i]) {
				bnd = false;
			}
		}

		return bnd;

	}

	// metodo que verifica que hayan variables para seguir
	private static int hayVariables(int tipo) {
		// tipo 0: canti1, tipo 1 :canti2
		if (tipo == 0) {
			for (int i = 0, j = (cantVariables.length - 1); i < cantVariables.length; i++, j--) {
				if (cantVariables[i].size() == 1) {
					return i;
				}

				if (cantVariables[j].size() == 1) {
					return j;
				}
			}

		} else {
			for (int i = 0, j = (cantVariables2.length - 1); i < cantVariables2.length; i++, j--) {
				if (cantVariables2[i].size() == 1) {
					return i;
				}

				if (cantVariables2[j].size() == 1) {
					return j;
				}
			}

		}

		return -1;
	}

	private static void reemplazarValor(String variable, long valorVariable) {
		resultados.put(variable, valorVariable);
		ArrayList<String> posiciones = mapa.get(variable);
		Iterator it = posiciones.iterator();
		while (it.hasNext()) {
			String pos[] = (it.next().toString()).split("&");
			int posInt[] = { Integer.parseInt(pos[0]), Integer.parseInt(pos[1]) };
			mat[posInt[0]][posInt[1]] = valorVariable + "";
			cantVariables[posInt[0]].remove(variable);
			cantVariables2[posInt[1]].remove(variable);

		}
	}

	private static void agregarAdyacencia(String variable, int i, int j) {

		Object dato = mapa.get(variable);
		if (dato == null) {
			ArrayList<String> x = new ArrayList<>();
			x.add(i + "&" + j);
			mapa.put(variable, x);
		} else {
			ArrayList<String> datoR = (ArrayList<String>) mapa.get(variable);
			datoR.add(i + "&" + j);
			mapa.put(variable, datoR);
		}

	}

	// SCANNER
	static class Scanner {
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		StringTokenizer st = new StringTokenizer("");
		int espacios = 0;

		public String nextLine() throws IOException {
			if (espacios > 0) {
				espacios--;
				return "";
			} else if (st.hasMoreTokens()) {
				StringBuilder salida = new StringBuilder();
				while (st.hasMoreTokens()) {
					salida.append(st.nextToken());
					if (st.countTokens() > 0) {
						salida.append(" ");
					}
				}
				return salida.toString();
			}
			return br.readLine();
		}

		public String next() throws IOException {
			espacios = 0;
			while (!st.hasMoreTokens()) {
				st = new StringTokenizer(br.readLine());
			}
			return st.nextToken();
		}

		public boolean hasNext() throws IOException {
			while (!st.hasMoreTokens()) {
				String linea = br.readLine();
				if (linea == null) {
					return false;
				}
				if (linea.equals("")) {
					espacios++;
				}
				st = new StringTokenizer(linea);
			}
			return true;
		}
	}

}
