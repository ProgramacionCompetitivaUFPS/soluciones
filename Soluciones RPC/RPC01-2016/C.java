/********************************************************************
 * Ejercicio:  C Colbys Costly Collectibles                         *
 * Url: https://acm.javeriana.edu.co/maratones/2016/01/             *
 * Lenguaje: java                                                   *
 * Autor: Si WA Meli nos golpea (Melissa Delgado - Daniel Vega -    *
 * Gerson Lázaro                                                    *
 * Fecha: 14-02-2016                                                *
 * Comentarios: Cambiar nombre del archivo a colby.java             *
 *******************************************************************/
 
 
import java.util.*;
import java.lang.*;
import java.io.*;

class Point { 
	double x, y;
  	public Point() { 
  		this.x = this.y = 0.0; 
  	}
  	public Point(double _x, double _y){
  		this.x = _x;
  		this.y = _y;
  	} 
  	public double getX(){
  		return this.x;
  	}
  	public double getY(){
  		return this.y;
  	}
  	public boolean equals(Point other){
  		if(Math.abs(this.x - other.getX()) < 1e-9 && (Math.abs(this.y - other.getY()) < 1e-9)) {
  			return true;
  		}
  		return false;
  	}
}

public class colby {
	
	
	public static double area(ArrayList<Point> P) {
		double result = 0.0, x1, y1, x2, y2;
	  	for (int i = 0; i < P.size()-1; i++) {
	    	x1 = P.get(i).getX(); 
	    	x2 = P.get(i+1).getX();
	    	y1 = P.get(i).getY(); 
	    	y2 = P.get(i+1).getY();
	    	result += ((x1 * y2) - (x2 * y1));
	  	}
	  	return Math.abs(result) / 2.0; 
}
	
	public static void main (String[] args) throws java.lang.Exception {
		int t, i, n, num;
		double x, y;
		char caracter;
		Scanner sc = new Scanner(System.in); //Se recomienda cambiar Scanner por el contenido en el notebook
		ArrayList<Point> figura;
		t = Integer.parseInt(sc.next());
		while(t > 0){
			n = Integer.parseInt(sc.next());
			figura = new ArrayList<Point>();
			x = y = 0;
			figura.add(new Point(x,y));
			for(i = 0; i < n; i++){
				caracter = sc.next().charAt(0);
				num = Integer.parseInt(sc.next());
				if(caracter == 'x'){
					x += num;
					
				}else if(caracter == 'y'){
					y += num;
					x += (double)num / 2;
				}else if(caracter == 'z'){
					y += num;
					x -= (double)num / 2;
				}
				figura.add(new Point(x, y));
			}
			System.out.println((int)(area(figura) * 2));
			t--;
		}
	}
}
