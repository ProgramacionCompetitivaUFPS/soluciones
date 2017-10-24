/********************************************************************
 * Ejercicio:  F - Factorial                                        *
 * Lenguaje: c++                                                    *
 * Autor: Elizabeth Ramirez                                         *
 * Fecha: 12-09-2016                                                *
 *******************************************************************/


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class F {
            public static void main(String[] args) throws IOException {
                Scanner sc=new Scanner();
                int x=Integer.parseInt(sc.next());
                if(x>=1&&x<=100000){
                    int []aux=new int[9];
                    aux[8]=1;
                    aux[7]=2;
                    aux[6]=6;
                    aux[5]=24;
                    aux[4]=120;
                    aux[3]=720;
                    aux[2]=5040;
                    aux[1]=40320;
                    aux[0]=362880;
                    int r=0,contador=0;
                    while(x!=r){
                        for (int j=0; j < aux.length; j++) {
                            if(aux[j]<x&&(aux[j]+r)<=x){
                                    r+=aux[j];
                                    contador+=1;
                                    break;
                            }
                        }
                    }
                    System.out.println(contador);
                }else{
                    System.out.println("el numero maximo es 100000");   
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

