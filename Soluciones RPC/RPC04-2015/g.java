/********************************************************************
 * Ejercicio: Gatuno's Fiber                                        *
 * Url: https://acm.javeriana.edu.co/maratones/2015/04              *
 * Lenguaje: java                                                   *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 09-05-2015                                                *
 *******************************************************************/

import java.io.*;
import java.util.HashMap;
import java.util.StringTokenizer;
import java.util.Map;

/**
 *
 * @author Bhaskara's Formulae :v
 */

public class base32{
    
    public static void main(String [] args) throws IOException{
        Scanner sc=new Scanner();
        OutputWriter out = new OutputWriter(System.out);
        int n;
        int num, i, y;
        StringBuilder convertir=new StringBuilder(40);
        StringBuilder aux=new StringBuilder(5);
        String binario;
        HashMap<String,Character> diccionario=new HashMap<String, Character>();
        
        diccionario.put("00000", '!');
        diccionario.put("00001", '@');
        diccionario.put("00010", '#');
        diccionario.put("00011", '$');
        diccionario.put("00100", '%');
        diccionario.put("00101", '&');
        y=97;
        for(i=6; i<32; i++, y++){
            binario=Integer.toBinaryString(i);
            while(binario.length()<5){
                binario=0+binario;
            }
            diccionario.put(binario, (char) (y));
        }
  
        while(sc.hasNext()){
            num=sc.nextInt();
            binario=Integer.toBinaryString(num);
            for(i=0; i<(8-binario.length()); i++){
                convertir.append('0');
            }
            convertir.append(binario);
        }

        n=0;
        while(convertir.length()>0){
            n++;
            if(convertir.length()>5){
                aux.append(convertir.substring(0, 5));
                convertir.delete(0, 5);
             }else{
                aux.append(convertir.substring(0, convertir.length()));
                convertir.delete(0, convertir.length());
            }
                    
                    
            while(aux.length()<5){
                aux.append('0');
            }
            out.print(diccionario.get(aux.toString())); 
            aux.delete(0,5);

            if(n==80){
                out.print("\n");
                n=0;
            }
        }
        out.print("\n");
        out.close();
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
        
    }
    
    static class OutputWriter{
          BufferedWriter writer;
         
          public OutputWriter(OutputStream stream){
            writer = new BufferedWriter(new OutputStreamWriter(stream));
          }
         
          public void print(int i) throws IOException {
            writer.write(i);
          }
         
          public void print(String s) throws IOException {
            writer.write(s);
          }
         
          public void print(char []c) throws IOException {
            writer.write(c);
          }
          public  void close() throws IOException {
            writer.close();
          }
    }
}
