/********************************************************************
 * Ejercicio: Josephus lottery                                      *
 * Url: https://acm.javeriana.edu.co/maratones/2015/03_div2         *
 * Lenguaje: java                                                   *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 11-04-2015                                                *
 *******************************************************************/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class josephusd2 {

    static class Scanner {

        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        StringTokenizer st = new StringTokenizer("");

        public String next() throws IOException {
            while (!st.hasMoreTokens()) {
                st = new StringTokenizer(br.readLine());
            }
            return st.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

    }

    public static void main(String[] args) throws IOException {
        int a, b, i, pos;
        Scanner sc = new Scanner();
        PrintWriter so = new PrintWriter(System.out);
        a = sc.nextInt();
        b = sc.nextInt();
        ArrayList<Integer> valores= new ArrayList<Integer>();
        boolean bandera;
        while (a != 0 && b != 0) {
            for (i = 1; i <= a; i++) {
                valores.add(i);
            }
            pos = 0;
            b--;
            bandera = true;
            while (valores.size() != 1) {
                if (bandera) {
                    pos += b;
                    while (pos >= valores.size()) {
                        pos = pos % valores.size();
                    }

                    valores.remove(pos);
                    while (pos >= valores.size()) {
                        pos = pos % valores.size();
                    }
                } else {
                    pos -= b;
                    while(pos < 0){
                        pos = valores.size() + pos;
                    }
                    valores.remove(pos);
                    pos--;
                    while(pos < 0){
                        pos = valores.size() + pos;
                    }
                }
                bandera = !bandera;
            }
            so.println(valores.get(0));
            a = sc.nextInt();
            b = sc.nextInt();
            valores.clear();
        }
        so.flush();
    }
}
