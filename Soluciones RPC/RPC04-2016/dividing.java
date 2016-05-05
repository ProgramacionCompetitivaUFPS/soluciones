/********************************************************************
 * Ejercicio: D                                                     *
 * Url: hhttps://acm.javeriana.edu.co/maratones/2016/04/            *
 * Lenguaje: java                                                   *
 * Autor: Pied Piper (Melissa Delgado - Daniel Vega - Gerson Lázaro)*                                                    *
 * Fecha: 30-04-2016                                                *
 *******************************************************************/

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;


public class dividing
{
	public static void main (String[] args) throws java.lang.Exception
	{
		BigInteger number;
        BigInteger mult = new BigInteger("17");
        BigInteger zero = new BigInteger("0");
        String input;
        Scanner scanner = new Scanner();
        while(scanner.hasNext()){
            input = scanner.next();
            number = new BigInteger(input,16);
            if(number.mod(mult).compareTo(zero) == 0){
                System.out.println("yes");
            }else{
                System.out.println("no");
            }
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