/********************************************************************
 * Ejercicio: Simple Base Conversion                                *
 * Url: https://www.urionlinejudge.com.br/judge/es/problems/view/1371
 * Lenguaje: java                                                   *
 * Autor: Gerson Lázaro                                             *
 * Fecha: 04-02-2016                                                * 
 * Comentarios: En java la clase y el archivo deben llamarse igual  *
 *        por lo tanto, antes de usar este código, asegurese de     *
 *        cambiar el nombre del archivo.                            *
 *******************************************************************/
 


import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
	public static long hexaToInt(String hex) {
  		return Long.parseLong(hex, 16);  
	}
	
	public static String intToHexa(long n){
		return Long.toHexString(n).toUpperCase();
	}
	
	public static void main (String[] args) throws java.lang.Exception {
		Scanner sc = new Scanner();
		String n = sc.next();
		while(n.charAt(0) != '-'){
			if(n.length() > 2 && n.charAt(1) == 'x'){
				System.out.println(hexaToInt(n.substring(2)));
			}else{
				System.out.println("0x"+intToHexa(Long.parseLong(n)));
			}
			n = sc.next();
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
