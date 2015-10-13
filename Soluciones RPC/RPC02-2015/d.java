/********************************************************************
 * Ejercicio: Flip Five                                             *
 * Url: https://acm.javeriana.edu.co/maratones/2015/02              *
 * Lenguaje: c++                                                    *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 14-03-2015                                                *
 *******************************************************************/

import java.util.Scanner;

public class flip {

    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        boolean [] ec;
        StringBuilder linea;
        
        
        while(n-->0){
            ec = new boolean[9];
            
            
            
                linea = new StringBuilder();
                linea.append(sc.next());
                linea.append(sc.next());
                linea.append(sc.next());
                for (int j = 0; j < linea.length(); j++) {
                    if(linea.charAt(j) == '*'){
                        ec[j] = true;
                    }
                }
            
            int con = 0;
            con += suma5(ec[0], ec[2], ec[5], ec[6], ec[7]);
            con += suma4(ec[4], ec[6], ec[7], ec[8]);
            con += suma5(ec[0], ec[2], ec[3], ec[7], ec[8]);
            con += suma4(ec[2], ec[4], ec[5], ec[8]);
            con += suma5(ec[1], ec[3], ec[4], ec[5], ec[7]);
            con += suma4(ec[0], ec[3], ec[4], ec[6]);
            con += suma5(ec[0], ec[1], ec[5], ec[6], ec[8]);
            con += suma4(ec[0], ec[1], ec[2], ec[4]);
            con += suma5(ec[1], ec[2], ec[3], ec[6], ec[8]);
            System.out.println(con);
        }
        
        
        
    }
    
    static int suma5(boolean n1, boolean n2, boolean n3, boolean n4, boolean n5){
        if((n1 && n2) || (!n1 && !n2)){
            n2 = false;
        }else{
            n2 = true;
        }
        if((n2 && n3) || (!n2 && !n3)){
            n3 = false;
        }else{
            n3 = true;
        }
        if((n3 && n4) || (!n3 && !n4)){
            n4 = false;
        }else{
            n4 = true;
        }
        if((n4 && n5) || (!n4 && !n5)){
            n5 = false;
        }else{
            n5 = true;
        }
        
        if(n5)
            return 1;
        return 0;
        
    }
    
    static int suma4(boolean n1, boolean n2, boolean n3, boolean n4){
         if((n1 && n2) || (!n1 && !n2)){
            n2 = false;
        }else{
            n2 = true;
        }
        if((n2 && n3) || (!n2 && !n3)){
            n3 = false;
        }else{
            n3 = true;
        }
        if((n3 && n4) || (!n3 && !n4)){
            n4 = false;
        }else{
            n4 = true;
        }
        
        
        if(n4)
            return 1;
        return 0;
    }
}

