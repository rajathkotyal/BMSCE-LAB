import java.util.*;

public class crc{
    public static int n;

    public static void main(String[] args){
        Scanner in=new Scanner(System.in);
        crc ob=new crc();

        String code, copy, rec,zero="0000000000000000";

        System.out.print("Enter poly: ");
        code=in.nextLine();

        System.out.println("Generating polynomial: 10001000000100001");

        n=code.length();
        copy=code;
        code+=zero;

        System.out.println("Modified poly: "+code);
        code=ob.divide(code);

        System.out.println("CheckSum: "+code.substring(n));
        copy=copy.substring(0,n)+code.substring(n);
        System.out.println("Final Codeword: "+copy);

        System.out.print("Test Error detection 0(yes) 1(no)? : ");
        int choice = in.nextInt();

        if(choice == 0){
            System.out.print("Enter position on error: ");
            int errorPos = in.nextInt();

            if(copy.charAt(errorPos) == '1')
                copy = copy.substring(0,errorPos) + "0" + copy.substring(errorPos+1);
            else
                copy = copy.substring(0,errorPos) + "1" + copy.substring(errorPos+1);

            System.out.println("Errorneous data: "+copy);

            System.out.println("Error detected");
        }
        else
            System.out.println("No Error detection");
    }

    public String divide(String s){
        int i,j;
        char x;
        String div="10001000000100001";

        for(i=0;i<n;i++){
            x=s.charAt(i);

            for(j=0;j<17;j++){
                if(x=='1'){
                    if(s.charAt(i+j)!=div.charAt(j))
                        s=s.substring(0,i+j)+"1"+s.substring(i+j+1);
                    else
                        s=s.substring(0,i+j)+"0"+s.substring(i+j+1);
                }
            }
        }

        return s;
    }
}