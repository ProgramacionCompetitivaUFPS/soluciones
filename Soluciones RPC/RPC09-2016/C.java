/********************************************************************
 * Ejercicio:  C - Tri-du                                           *
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

public class C {
            public static void main(String[] args) throws IOException {
                Scanner sc=new Scanner();
                int x=Integer.parseInt(sc.next());
                int y=Integer.parseInt(sc.next());
                if ((x >= 1 && x <= 13) && (y >= 1 && y <= 13)) {
                    if (x < y) {
                        System.out.println(y);
                    } else {
                        System.out.println(x);
                    }
                }else if((x<1&&x > 13)&&(y >= 1 && y <= 13)){
                    System.out.println(y);
                }else if((y<1&&y > 13)&&(x >= 1 && x <= 13)){
                    System.out.println(x);
                }else{
                    System.out.println("sus numeros sobrepasan a 13");
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

