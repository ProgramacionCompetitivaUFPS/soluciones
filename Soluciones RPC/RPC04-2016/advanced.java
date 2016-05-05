/********************************************************************
 * Ejercicio: A                                                     *
 * Url: hhttps://acm.javeriana.edu.co/maratones/2016/04/            *
 * Lenguaje: java                                                   *
 * Autor: Pied Piper (Melissa Delgado - Daniel Vega - Gerson Lázaro)*                                                    *
 * Fecha: 30-04-2016                                                *
 *******************************************************************/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;


public class advanced {

   
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner();
        PrintWriter pw = new PrintWriter(System.out);
        String cant = sc.next();
        long rta;
        BigInteger val, dos = new BigInteger("2"), putoDiez = new BigInteger("10000000000");
        while(!cant.equals("0")) {
            val = new BigInteger(cant);
            val = val.multiply(val.add(BigInteger.ONE));
            val = val.divide(dos);
            val = val.multiply(val);
            rta = Long.parseLong(val.mod(putoDiez).toString());
            pw.println(rta);
            cant = sc.next();
        }
        pw.flush();
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
