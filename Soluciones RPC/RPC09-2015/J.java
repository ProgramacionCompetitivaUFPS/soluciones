/********************************************************************
 * Ejercicio: Strategy Game                                         *
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

public class J {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner();
        int a=0,b=0;
        int [][] juego;
        int suma=0;
        int aux=0;
        int pos=0;
        while(sc.hasNext()){
            b=Integer.parseInt(sc.next());
            a=Integer.parseInt(sc.next());
            juego= new int [a+1][b];
            for (int i = 0; i < a; i++) {
                for (int j = 0; j < b; j++) {
                    juego[i][j]=Integer.parseInt(sc.next());
                    suma=juego[i][j];
                    juego[a][j]+=suma;
                    suma=0;
                }
                
            }
           suma=0;
            for (int i = 0; i < b; i++) {
                if(suma<=juego[a][i]){
                    suma=juego[a][i];
                    pos=i+1;
                }
            }
            System.out.println(pos);
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
