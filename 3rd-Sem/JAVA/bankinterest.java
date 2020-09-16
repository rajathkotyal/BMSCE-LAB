import java.util.*;
import java.lang.Math.*;
class bank
{
	public String name;
	public int acc_no;
	public double bal;

	public void accept()
	{
		Scanner s=new Scanner(System.in);
		System.out.print("\nEnter the name of the account holder: ");
		name=s.next();
		System.out.print("Enter the account number: ");
		acc_no=s.nextInt();
		System.out.print("Enter the account balance: ");
		bal=s.nextDouble();
	}

	public void display()
	{
		System.out.println("\n************************\n");
		System.out.println("Name: "+name+"\nAccount number: "+acc_no+"\nBalance: Rs"+bal);
	}

}

class savings extends bank
{
	public void cheque()
	{
		System.out.println("\nNo cheque services");
	}

	public void withdrawal()
	{
		float amount;
		Scanner a=new Scanner(System.in);
		System.out.println("\nNo minimun balance required");
		System.out.print("Enter the amount to be withdrawm: ");
		amount=a.nextFloat();
		if(amount>super.bal)
		{
			System.out.println("Balance is insufficient");
		}
		else
		{
			super.bal=super.bal-amount;
			System.out.println(amount+" withdrawm");
			System.out.println("Available balance: Rs"+super.bal);
		}
	}

	public void compound_interest(){
		System.out.println("\nRate of interest: 8%");
		int time;
		Scanner c=new Scanner(System.in);
		System.out.print("\nEnter time: ");
		time=c.nextInt();
		double ci=super.bal*(Math.pow((1+8.0/100),time)) - super.bal;
		System.out.println("Compound Interest: Rs"+ci);
		super.bal=super.bal+(float)ci;
		System.out.println("Available balance: Rs"+super.bal);
	}
}

class current extends bank
{
	public void cheque()
	{
		System.out.println("\nCheque services available");
	}

	public void withdrawal()
	{
		float amount;
		Scanner a=new Scanner(System.in);
		System.out.println("\nMinimun balance= Rs.1000.00");
		if(super.bal<1000)
			System.out.println("Balance is insufficient to withdraw");
		else
		{
			System.out.print("Enter the amount to be withdrawm: ");
			amount=a.nextFloat();
			if(amount>(super.bal-1000))
			{
				System.out.println("Balance is insufficient");
			}
			else
			{
				super.bal=super.bal-amount;
				System.out.println(amount+" withdrawm");
				System.out.println("Available balance= "+super.bal);
			}
		}
	}

	public void penalty()
	{
		if(super.bal<1000)
		{
			System.out.print("\nPenalty rate: 10%");
			double penalty=super.bal*(10.0/100);
			super.bal=super.bal-penalty;
			System.out.println("Penalty amount: Rs"+penalty);
			System.out.println("Available balance: Rs"+super.bal);
		}
	}
		
}

class bankinterest
{
	public static void main(String args[])
	{
		savings obj1[]=new savings[3];
		current obj2[]=new current[3];
		System.out.print("Enter the number of accounts: ");
		Scanner x=new Scanner(System.in);
		int n=x.nextInt();
		int i=0;
		int j=0;
		int k=0;
		while(i<n)
		{
			System.out.println("\nAccount "+(i+1));
			System.out.println("\n1)Savings\n2)Current");
			System.out.print("Enter the type of account: ");
			int ch=x.nextInt();
			if(ch==1)
			{
				obj1[j]=new savings();
				obj1[j].accept();
				obj1[j].display();
				obj1[j].cheque();
				obj1[j].compound_interest();
				obj1[j].withdrawal();
				j++;
			}
			else
			{
				obj2[k]=new current();
				obj2[k].accept();
				obj2[k].display();
				obj2[k].cheque();
				obj2[k].withdrawal();
				obj2[k].penalty();
				k++;
			}
			i++;
		}
	}
}
