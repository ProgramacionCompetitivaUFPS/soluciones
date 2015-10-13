/********************************************************************
 * Ejercicio: Factorial                                             *
 * Url: https://acm.javeriana.edu.co/maratones/2015/09/             *
 * Lenguaje: java                                                   *
 * Autor: "no C deJava codear :v" (David Tolosa, Juan Manuel        *
            Huertas, Diana Villamizar)                              *
 * Fecha: 12-09-2015                                                *
 *******************************************************************/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class F {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner();
        int c = 0;
        int[] factoriales = new int[8];
        int res = 1;
        int num = 0;
        int count = 0;
        for (int i = 0; i < factoriales.length; i++) {
            res = (i + 1) * res;
            factoriales[i] = res;
        }

        while (sc.hasNext()) {
            res = 0;
            count = 0;
            num = Integer.parseInt(sc.next());
            for (int i = factoriales.length - 1; i >= 0; i--) {
                if ((factoriales[i] + res) <= num) {
                    res += factoriales[i];
                    count++;
                    i++;
                }

            }
            System.out.println(count);
        }
    }

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
