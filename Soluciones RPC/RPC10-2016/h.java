/********************************************************************
 * Ejercicio:  H - Haciendo la tarea                                *
 * Lenguaje: java                                                    *
 * Autor: Elizabeth Ramirez                                         *
 * Fecha: 26-09-2016                                                *
 *******************************************************************/

import java.io.IOException;

import java.util.ArrayList;

import java.util.Collections;

import java.util.Scanner;


public class h {


        public static void main(String[] args) throws IOException {
            Scanner nc=new Scanner(System.in);
           int x=nc.nextInt();
                int resultado=x;
                String numeroF=""+x;
                int cont=0;
                while(resultado!=0) {
                    ArrayList<Character> mm=new ArrayList<>();
                    for (int j = 0; j < numeroF.length(); j++) {
                        mm.add(numeroF.charAt(j));
                    }
                       Collections.sort(mm);
                       numeroF="";
                    for (int i = 0; i < mm.size(); i++) {
                        numeroF+=mm.get(i);
                    }
                    resultado-=Integer.parseInt(numeroF);
                    numeroF=""+resultado;
                    cont+=1;
                }
                System.out.println(cont);
            
        }
     
}
