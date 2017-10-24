/********************************************************************
 * Ejercicio:  J - Strategy Game                                    *
 * Lenguaje: c++                                                    *
 * Autor: Elizabeth Ramirez                                         *
 * Fecha: 12-09-2016                                                *
 *******************************************************************/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class J {
            public static void main(String[] args) throws IOException {
                Scanner sc=new Scanner();
                while(sc.hasNext()){
                int columnas=Integer.parseInt(sc.next());
                int filas=Integer.parseInt(sc.next());
                int [][]puntajes=new int[filas][columnas];
                int []aux=new int[columnas];
                for (int i = 0; i < filas; i++) {
                    for (int j = 0; j < columnas; j++) {
                        puntajes[i][j]=Integer.parseInt(sc.next());
                        aux[j]+=puntajes[i][j];
                    }
                }
                int x=0,r=0;
                for (int i = 0; i < aux.length; i++) {
                    if(aux[i]>r|aux[i]==r){
                        r=aux[i];
                        x=i+1;
                    }
                    
                }
                System.out.println(x);
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

