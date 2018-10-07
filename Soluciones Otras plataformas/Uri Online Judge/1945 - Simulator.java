/********************************************************************
 * Ejercicio: Simulator                                             *
 * Url: https://www.urionlinejudge.com.br/judge/es/problems/view/1945
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


public class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner();
		String aux[];
		TreeMap<String, Integer> mapa = new TreeMap<String, Integer>();
		int value, ult = 0;
		while(sc.hasNext()){
			aux = sc.nextLine().split(" ");
			if(aux.length == 3){
				if(mapa.containsKey(aux[2])){
					mapa.put(aux[0], mapa.get(aux[2]));
					ult = mapa.get(aux[2]);
 				}else{
 					mapa.put(aux[0], Integer.parseInt(aux[2]));
 					ult = Integer.parseInt(aux[2]);
 				}
			}else{
				value = 0;
				if(mapa.containsKey(aux[2])){
					value += mapa.get(aux[2]);
				}else{
					value += Integer.parseInt(aux[2]);
				}
				if(mapa.containsKey(aux[4])){
					value += mapa.get(aux[4]);
				}else{
					value += Integer.parseInt(aux[4]);
				}
				mapa.put(aux[0], value);
				ult = value;
			}
		}
		System.out.println(ult);
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
