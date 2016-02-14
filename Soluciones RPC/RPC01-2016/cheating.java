/********************************************************************
 * Ejercicio: A Cheating Knight                                     *
 * Url: https://acm.javeriana.edu.co/maratones/2016/01/             *
 * Lenguaje: java                                                   *
 * Autor: Si WA Meli nos golpea (Melissa Delgado - Daniel Vega -    *
 * Gerson Lázaro                                                    *
 * Fecha: 14-02-2016                                                *
 *******************************************************************/


import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class cheating
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner();
		int t = Integer.parseInt(sc.next());
		double d, x, y, dist;
		while(t > 0){
			d = Double.parseDouble(sc.next());
			x = Double.parseDouble(sc.next());
			y = Double.parseDouble(sc.next());
			dist = Math.sqrt((x * x + y * y) / d );
			if(dist > 0 && dist < 1){
				dist = 2;
			}
			System.out.printf("%.0f\n",Math.ceil(dist));
			t--;
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