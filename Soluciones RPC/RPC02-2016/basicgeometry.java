/**********************************************************************
 * Ejercicio:  G Basic Geometry                                       *
 * Url: https://acm.javeriana.edu.co/maratones/2016/02/               *
 * Lenguaje: java                                                     *
 * Autor: sort(my_life)(Melissa Delgado - Daniel Vega - Gerson Lázaro *                                                   *
 * Fecha: 12-03-2016                                                  *
 *********************************************************************/

import java.util.*;
import java.lang.*;
import java.io.*;

public class basicgeometry {
	public static void main (String[] args) throws java.lang.Exception {
		Scanner sc = new Scanner();
		double a, b;
		double R, h, area, teta;
		while(sc.hasNext()) {
			a = Double.parseDouble(sc.next());
			b = Double.parseDouble(sc.next());
			R = ((2 * a) + (2 * b)) / 2;
			h = 2 * b;
			teta = 2 * Math.acos((R - (2 * b)) / R);
			area = (R * R / 2) * (teta - Math.sin(teta));
			area -= (Math.PI * b * b);
			System.out.printf("%.3f\n", area);
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