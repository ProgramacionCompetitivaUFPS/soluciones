/********************************************************************
 * Ejercicio:  J - Digit Counting                                   *
 * Lenguaje: Java                                                   *
 * Autor: Wingardium Leviosa (Melissa Delgado - Daniel Vega -       *
 * Gerson Lázaro                                                    *
 * Fecha: 22-10-2016                                                *
 *******************************************************************/


import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

public class digit {
	
	public static void main (String[] args) throws java.lang.Exception {
		int memo[][] = new int[10000][10];
		Scanner sc = new Scanner();
		PrintWriter pw = new PrintWriter(System.out);
		int j;
		for(int i = 1; i < 10000; i++) {
			j = i;
			for(int k = 0; k < 10; k++) {
				memo[i][k] = memo[i - 1][k];
			}
			while(j > 0) {
				memo[i][j % 10]++;
				j /= 10;
			}
		}
		int d;
		int n = Integer.parseInt(sc.next());
		while(n-- > 0) {
			d =  Integer.parseInt(sc.next());
			System.out.println(memo[d][0] + " " + memo[d][1] + " " + memo[d][2] + " " + memo[d][3] + " " + memo[d][4] + " " + memo[d][5] + " " + memo[d][6] + " " + memo[d][7] + " " + memo[d][8] + " " + memo[d][9]);
		}
	}
	
	static class Scanner{
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        StringTokenizer st = new StringTokenizer("");
        int espacios = 0;

        public String nextLine() throws IOException{
        	if(espacios>0){
            	espacios--;
            	return "";
            }else if(st.hasMoreTokens()){
                StringBuilder salida = new StringBuilder();
                while(st.hasMoreTokens()){
                    salida.append(st.nextToken());
                    if(st.countTokens()>0){
                        salida.append(" ");
                    }
                }
                return salida.toString();
            }
            return br.readLine();
        }

        public String next() throws IOException{
        	espacios=0;
            while (!st.hasMoreTokens() ) {
                st = new StringTokenizer(br.readLine() );
            }
            return st.nextToken();
        }

        public boolean hasNext() throws IOException{
            while (!st.hasMoreTokens()) {
                String linea = br.readLine();
                if (linea == null) {
                    return false;
                }
                if(linea.equals("")){
                	espacios++;
                }
                st = new StringTokenizer(linea);
            }
            return true;
        }
    }
}