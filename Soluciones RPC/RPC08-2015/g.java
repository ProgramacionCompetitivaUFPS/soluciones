/********************************************************************
 * Ejercicio: Extreme Sort                                          *
 * Url: https://acm.javeriana.edu.co/maratones/2015/08              *
 * Lenguaje: java                                                   *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 08-08-2015                                                *
 *******************************************************************/

import java.util.*;
import java.io.*;


public class extreme {
	public static void main (String[] args)  throws IOException{
		Scanner sc = new Scanner();
		PrintWriter bw = new PrintWriter(System.out);
		
		int N, anterior, actual;
		boolean flag = true;
		
		N = Integer.parseInt(sc.next());
		anterior = Integer.parseInt( sc.next() );
		
		for(int i=1;i<N;i++){
			actual = Integer.parseInt( sc.next() );
			if(actual < anterior){
				flag = false;
			}
			anterior = actual;
		}
		if(flag){
			bw.println("yes");
		}else{
			bw.println("no");
		}
		bw.flush();
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