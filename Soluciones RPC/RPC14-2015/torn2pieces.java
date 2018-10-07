/********************************************************************
 * Ejercicio: K                                                     *
 * Url: https://acm.javeriana.edu.co/maratones/2015/14              *
 * Lenguaje: java                                                   *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 28-11-2015                                                *
 *******************************************************************/

import java.util.*;

public class torn2pieces {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n, src, dest, j, tam;
        String s, d, line;
        String vectorsito[];

        ArrayList< ArrayList<Integer>> ady=new ArrayList< ArrayList<Integer>>();
        TreeMap<String, Integer> claves = new TreeMap<String, Integer>();
        TreeMap<Integer, String> estaciones = new TreeMap<Integer, String>();
        n = sc.nextInt();

        sc.nextLine();

        int i = 0;

        while (n > 0) {
            line = sc.nextLine();
            vectorsito = line.split(" ");

            if (!claves.containsKey(vectorsito[0])) {
                claves.put(vectorsito[0], i);
                estaciones.put(i, vectorsito[0]);
                ady.add(new ArrayList<Integer>());
                i++;
            }
            src = claves.get(vectorsito[0]);

            for (j = 1; j < vectorsito.length; j++) {
                if (!claves.containsKey(vectorsito[j])) {
                    claves.put(vectorsito[j], i);
                    estaciones.put(i, vectorsito[j]);
                    ady.add(new ArrayList<Integer>());
                    i++;
                }
                dest = claves.get(vectorsito[j]);
                ady.get(src).add(dest);
                ady.get(dest).add(src);
            }
            n--;
        }
        
        tam=ady.size();
        boolean vis[]=new boolean[tam];
        int prev[]=new int[tam];
        
        line = sc.nextLine();
        vectorsito = line.split(" ");
        
        if(!claves.containsKey(vectorsito[0]) || !claves.containsKey(vectorsito[1])){
            System.out.println("no route found");
        }else{
            src=claves.get(vectorsito[0]);
            dest=claves.get(vectorsito[1]);
            prev[src]=-1;
            dfs(ady, vis, prev, src, dest);
            if(vis[dest]){
                imprimir(dest, prev, estaciones);
                System.out.println("");
            }else{
                System.out.println("no route found");
            }
        }


    }
    
    static void imprimir(int dest, int[] prev, TreeMap claves){
        if(prev[dest]==-1){
            System.out.print(claves.get(dest));
        }else{
            imprimir(prev[dest], prev, claves);
            System.out.print(" "+claves.get(dest));
        }
    }
    
    static void dfs(ArrayList ady, boolean []vis, int [] prev, int src, int dest){
        vis[src]=true;
        int p;
        if(src==dest){
            return;
        }
        ArrayList<Integer> x=(ArrayList<Integer>) ady.get(src);
        for(int i=0; i<x.size(); i++){
            p=x.get(i);
            if(!vis[p]){
                prev[p]=src;
                dfs(ady, vis, prev, p, dest);
            }
        }
        
    }

}
