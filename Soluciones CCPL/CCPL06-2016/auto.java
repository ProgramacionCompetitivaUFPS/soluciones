/********************************************************************
 * Ejercicio:  A - Automorphic Numbers                              *
 * Lenguaje: java                                                   *
 * Autor: Si WA Meli nos golpea (Melissa Delgado - Daniel Vega -    *
 * Gerson Lázaro                                                    *
 * Fecha: 04-06-2016                                                *
 *******************************************************************/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;


public class auto {
    public static void main(String []args) throws IOException {
        Scanner sc = new Scanner();
        PrintWriter pw = new PrintWriter(System.out);
        StringBuilder ab, c,cd;
        BigInteger a, b;
        int tam;
        BigInteger dos = new BigInteger("2");
        while(sc.hasNext()) {
            ab = new StringBuilder(sc.next());
            a = new BigInteger(ab.toString());
            if(a.compareTo(dos) > 0){
                b = a.pow(2);
                cd = new StringBuilder(b.toString());
                tam = cd.length() - ab.length();
                if(tam >= 0) {
                    c = new StringBuilder(cd.substring(tam, cd.length()));
                }else {
                    tam *= -1;
                    c = new StringBuilder();
                    for(int x = 0; x < tam; x++) {
                        c.append(0);
                    }
                    c.append(cd);
                }
                
                if(ab.toString().equals(c.toString())) {
                    pw.printf("Automorphic number of %d-digit.\n", ab.length());
                }else {
                    pw.println("Not an Automorphic number.");
                }
            } else {
                pw.println("Not an Automorphic number.");
            }
        }
        pw.close();
        
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
