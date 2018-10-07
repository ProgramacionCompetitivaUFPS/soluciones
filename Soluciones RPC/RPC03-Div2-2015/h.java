/********************************************************************
 * Ejercicio: Pascals triangle: Sum of levels                       *
 * Url: https://acm.javeriana.edu.co/maratones/2015/03_div2         *
 * Lenguaje: java                                                   *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 11-04-2015                                                *
 *******************************************************************/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

import java.math.BigDecimal;
import java.math.BigInteger;

class pascald2 {
    
    public static void main(String []args) throws IOException{
        Scanner sc = new Scanner();
        
        int n = sc.nextInt();
        int m = sc.nextInt();

        BigInteger dos = new BigInteger("2");
        BigInteger a,b;
        PrintWriter f = new PrintWriter(System.out);
        BigInteger modulo=new BigInteger("1000007");
        while (n != -1 &&  m!= -1) {
            a = dos.pow(m+1);
            b = dos.pow(n);
            a = a.subtract(b).mod(modulo);
	    	f.println(a);
            n = sc.nextInt();
            m = sc.nextInt();
        }
	f.flush();
    }
    
    static class Scanner{
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        StringTokenizer st = new StringTokenizer("");
        
        
        public String nextLine() throws IOException{
            if(st.hasMoreTokens()){
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
            while ( !st.hasMoreTokens() ) {
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
                st = new StringTokenizer(linea);
            }
            return st.hasMoreTokens();
        }
        
        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
        
        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }
        
        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
        
        public double nextFloat() throws IOException {
            return Float.parseFloat(next());
        }
        
        public double nextShort() throws IOException {
            return Short.parseShort(next());
        }
        
        public double nextByte() throws IOException {
            return Byte.parseByte(next());
        }
        
        public BigDecimal nextBigDecimal() throws IOException{
            return new BigDecimal(next());
        }
        
        public BigInteger nextBigInteger() throws IOException{
            return new BigInteger(next());
        }
        
        public StringBuilder nextStringBuilder() throws IOException{
            return new StringBuilder(next());
        }
        
    }
}
