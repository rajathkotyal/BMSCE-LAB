import java.util.*;


class student 
{
        public String usn;
        public String name;
        public int credits[] = new int[6];
        public int marks[] = new int[6];
        public int i,j,k;
    
        
        public void inputdata()
        {
        	Scanner s = new Scanner();
        	System.out.println("Enter USN : ");
        	usn = S.nextLine();
        	
        	System.out.println("Enter Name : ");
        	name = S.nextLine();
        	
        	System.out.println("Enter Credits : ");
        	for(int i=0;i<5;i++)
        	{
        	int credits[i] = S.nextInt();
        	
        	for(int j=1;j<=5;j++)
        	{System.out.println("Enter Marks in Subject " +j);
        	
        	int marks[j] = S.nextInt();
        	
		if(marks[j]>=90)
		{
			tot+=10*credits;        
        	}
        	else if(marks[j]>=75)
		{
			tot+=9*credits;        
        	}
        	else if(marks[j]>=60)
		{
			tot+=8*credits;        
        	}
        	
        	else if(marks[j]>=50)
		{
			tot+=7*credits;        
        	}
        	else if(marks[j]>=45)
		{
			tot+=5*credits;        
        	}
        	else if(marks[j]>=40)
		{
			tot+=4*credits;        
        	}
        	
        	else
        	{
			tot+=0*credits[i];
        	
        	}
        	}
        	
        	system.out.println("Final Sgpa = " +(tot/20));
       }
       }
   
       public void display();
       {
		system.out.println("USN = " +usn);
		system.out.println("Name = " +name);
		system.out.println("Marks in Subjects: ");
		for(i=1;i<6;i++)
		{
			system.out.println("subject" +i+ " = "+marks[i]);
		}
		
		system.out.println("SGPA = " +tot);
		}
		

	
	public static void main(String args[])
	{
		student obj = new Scanner();
		
        	obj.inputdata();
        	obj.display();
        }
        }
        	
