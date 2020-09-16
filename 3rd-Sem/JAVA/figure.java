import java.util.*;
import java.lang.Math.*;

abstract class shape{
	public int a;
	public int b;
	abstract public void printArea();
	Scanner s=new Scanner(System.in);
}

class rectangle extends shape{
	public void printArea(){
		System.out.print("Enter length and breadth of rectangle: ");
		float a=s.nextFloat();
		float b=s.nextFloat();
		float area=a*b;
		System.out.println("Area="+area+"sq.units");
	}
}

class triangle extends shape{
	public void printArea(){
		System.out.print("Enter three sides of triangle: ");
		float a=s.nextFloat();
		float b=s.nextFloat();
		float c=s.nextFloat();
		float d=(a+b+c)/2;
		double area=Math.sqrt(d*(d-a)*(d-b)*(d-c));
		System.out.println("Area="+area+"sq.units");
	}
}

class circle extends shape{
	public void printArea(){
		System.out.print("Enter radius of circle: ");
		float a=s.nextFloat();
		float area=22/7*a*a;
		System.out.println("Area="+area+"sq.units");
	}
}

class figure{
	public static void main(String args[]){
		
		shape r=new rectangle();
		shape t=new triangle();
		shape c=new circle();
		for(int i=0;i<100;i++){
		System.out.println("\n1)Triangle\n2)Rectangle\n3)Circle");
		System.out.println("Enter your choice: ");
		Scanner s=new Scanner(System.in);
		int ch=s.nextInt();
		switch(ch){
			case 1: t.printArea();
			        break;
			case 2: r.printArea();
			        break;
            case 3: c.printArea();
                    break;
            default: System.out.println("Invalid choice");
		}
		}
	}
}
