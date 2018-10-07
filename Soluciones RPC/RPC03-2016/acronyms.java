/********************************************************************
 * Ejercicio:  A Acronyms    				                        *
 * Url: https://acm.javeriana.edu.co/maratones/2016/03/             *
 * Lenguaje: java                                                   *
 * Autor: MOV AX 4c00h (Melissa Delgado-Daniel Vega-Gerson Lázaro   * 
 * Fecha: 09-04-2016                                                *
 *******************************************************************/

import java.util.*;
import java.lang.*;
import java.io.*;


public class acronyms
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner scanner = new Scanner(System.in);
		String a,c;
		String[] authors,check;
		int i = 0;
		boolean isValid = true;
		while(scanner.hasNext()){
			a = scanner.nextLine();
			c = scanner.nextLine();
			authors = a.split(" ");
			check = c.split(" ");
			if(authors.length > check.length){
				System.out.println("no");
			}else{
				for(;i<authors.length;i++){
					if(authors[i].charAt(0) != check[i].charAt(0)){
						System.out.println("no");
						isValid = false;
						break;
					}
				}
				i = 0;
				if(isValid){
					System.out.println("yes");
				}
			}
			isValid = true;
		}
		
	}
}