/********************************************************************
 * Ejercicio:  G - The Owl and the Fox                              *
 * Lenguaje: Java                                                   *
 * Autor: Elizabeth Ramirez                                         *
 * Fecha: 08-08-2016                                                *
 *******************************************************************/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class owl{

    public static void main(String[] args) throws IOException {
       Scanner sc=new Scanner();
         PrintWriter out=new PrintWriter(System.out);
       while(true){
           String s=sc.next();
           if(s.equalsIgnoreCase("END")){
               break;
           }
           int aux=Integer.parseInt(s);
           int cont = calcular(aux);
           int r=cont;
           while(r>=cont){
                   aux-=1;
                   r=calcular(aux);
           }
            out.println(aux);
       }
        out.close();
    }
    public static int calcular(int numero){
        int cont=0;
        while (numero > 0) {
               cont += numero % 10;
               numero = numero / 10;
           }
        return cont;
    }
    
     static class Scanner {

        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        StringTokenizer st = new StringTokenizer("");
        int espacios = 0;

        public String nextLine() throws IOException {
            if (espacios > 0) {
                espacios--;
                return "";
            } else if (st.hasMoreTokens()) {
                StringBuilder salida = new StringBuilder();
                while (st.hasMoreTokens()) {
                    salida.append(st.nextToken());
                    if (st.countTokens() > 0) {
                        salida.append(" ");
                    }
                }
                return salida.toString();
            }
            return br.readLine();
        }

        public String next() throws IOException {
            espacios = 0;
            while (!st.hasMoreTokens()) {
                st = new StringTokenizer(br.readLine());
            }
            return st.nextToken();
        }

        public boolean hasNext() throws IOException {
            while (!st.hasMoreTokens()) {
                String linea = br.readLine();
                if (linea == null) {
                    return false;
                }
                if (linea.equals("")) {
                    espacios++;
                }
                st = new StringTokenizer(linea);
            }
            return true;
        }
    }
     
     
static ArrayList<Integer> table(String pattern){
	int m=pattern.length();
	ArrayList<Integer> border = new ArrayList<Integer>();
	border.add(0);
	int temp;
	for(int i=1; i<m; ++i){
		border.add(border.get(i-1));
		temp = border.get(i);
		while(temp>0 && pattern.charAt(i)!=pattern.charAt(temp)){
			if(temp <= i+1){
				border.set(i,border.get(temp-1));
				temp = border.get(i);
			}
		}
		if(pattern.charAt(i) == pattern.charAt(temp)){
			border.set(i,temp+1);
		}
	}
	return border;
}

static boolean kmp(String cadena, String pattern){
	int n=cadena.length();
	int m=pattern.length();
	ArrayList<Integer> tab=table(pattern);
	int seen=0;

	for(int i=0; i<n; i++){
		while(seen>0 && cadena.charAt(i)!=pattern.charAt(seen)){
			seen=tab.get(seen-1);
		}
		if(cadena.charAt(i)==pattern.charAt(seen))
			seen++;
		if(seen==m){
			return true;
		}
	}
	return false;
}
     
}
