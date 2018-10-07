/********************************************************************
 * Ejercicio:  K - Prime Kebab Menu			                        *
 * Lenguaje: java                                                   *
 * Autor: Si WA Meli nos golpea (Melissa Delgado - Daniel Vega -    *
 * Gerson Lázaro                                                    *
 * Fecha: 27-02-2016                                                *
 *******************************************************************/

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class kebab
{
	static int MAX = 10000010;
	static ArrayList<Integer> primes = new ArrayList<Integer>();
	static boolean sieve[] = new boolean[MAX+5];
		
	static void calculatePrimes() {
	  sieve[0] = sieve[1] = true;
	  int i;
	  for (i = 2; i * i <= MAX; ++i) {
	    if (!sieve[i]) {
	      primes.add(i);
	      for (int j = i * i; j <= MAX; j += i)
	        sieve[j] = true;
	    }
	  }
	  for(; i <= MAX; i++){
	  	if (!sieve[i]) {
	      primes.add(i);
	    }
	  }
	}
	


	static int calculatePrimeFactors(long value){
		int rta = 0;
		long temp = value;
		int factor;
		for (int i = 0; (long)primes.get(i) * primes.get(i) <= value; ++i){
			factor = primes.get(i);
			while (temp % factor == 0){
				rta++;
				temp /= factor;
			}
		}
		if (temp != 1) {
			rta++;
		}
		return rta;
	}
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner();
		calculatePrimes();
		long value = Long.parseLong(sc.next());
		while(value != 1){
			System.out.println(calculatePrimeFactors(value));
			value = Long.parseLong(sc.next());
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