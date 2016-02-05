/********************************************************************
 * Ejercicio: Sort by Length                                        *
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
	public static void main (String[] args) throws java.lang.Exception {
		Scanner sc = new Scanner();
		String palabra, pal[],aux;
		int i, j, casos = Integer.parseInt(sc.next());
		TreeMap<Integer, ArrayList<String> > mapa;
		ArrayList aux2;
		boolean flag;
		while(casos > 0){
			palabra = sc.nextLine();
			pal = palabra.split(" ");
			mapa = new TreeMap<Integer, ArrayList<String> >();
			for(i = 0; i < pal.length; i++){
				aux = pal[i];
				if(mapa.containsKey(aux.length())){
					aux2 = mapa.get(aux.length());
					aux2.add(aux);
				}else{
					aux2 = new ArrayList<String> ();
					aux2.add(aux);
					mapa.put(aux.length(), aux2);
				}
			}
			flag = false;
			for(i = 55; i >  0; i--){
				if(mapa.containsKey(i)){
					aux2 = mapa.get(i);
					for(j = 0; j < aux2.size(); j++){
						if(flag){
							System.out.print(" ");
						}
						System.out.print(aux2.get(j));
						flag = true;
					}
				}
			}
			System.out.println();
			casos--;
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
