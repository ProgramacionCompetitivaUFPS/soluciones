/********************************************************************
 * Ejercicio: Jolly Jumper                                          *
 * Url: https://uva.onlinejudge.org/index.php?option=com_           * onlinejudge&Itemid=8&category=24&page=show_problem&problem=979      *
 * Lenguaje: java                                                   *
 * Autor: Crysel Ayala                                              *
 * Fecha: 24-09-2015                                                *
 *******************************************************************/
 
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main {

    public static void main(String[] args) throws IOException {

        Scanner sc = new Scanner();

        while (sc.hasNext()) {
            int n = Integer.parseInt(sc.next());

            int[] jolly = new int[n];
            int[] diferencia = new int[n - 1];
            boolean [] aux = new boolean [n];
            boolean bandera = true;

            for (int i = 0; i < n; i++) {
                jolly[i] = Integer.parseInt(sc.next());
            }

            for (int i = 0; i < n - 1; i++) {
                diferencia[i] = Math.abs(jolly[i] - jolly[i + 1]);

                if (diferencia[i] < 1 || diferencia[i] >= n || aux[diferencia[i]]) {
                    bandera = false;
                    System.out.println("Not jolly");
                    break;
                }
                aux[diferencia[i]]=true;
            }
            
            if(bandera){
                System.out.println("Jolly");
            }
            

        }
    }

    static class Scanner {

        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        StringTokenizer st = new StringTokenizer("");
        int espacios = 0;

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
