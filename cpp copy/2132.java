import java.util.Scanner;

public class 单词接龙 {
	private static int n=0,max=0;
    private static String a[];
    private static int visit[];
    private static String s1,s,tmp;
    private static char st;
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        a=new String[n];
        for (int i = 0; i < n; i++) {
            a[i]=sc.next();
        }
        s=sc.next();
        st=s.charAt(0);
        visit=new int[n];
        sc.close();
        for (int k = 0; k < a.length; k++) {
            if (findS1(a[k])) { 
                dfs(s1); 
            }
        }
        System.out.println(max);
    }
    public static void dfs(String ss){
        String temp="";
        temp=ss;
        if (max<=ss.length()) {
            max=ss.length();
        }
                for (int i = 0; i < a.length; i++){ 
                    if (visit[i]<2&&checkString(ss,a[i] )&&contact(ss, a[i])) {
                        visit[i]++;
                        ss=tmp;
                        dfs(ss);
                        ss=temp;
                        visit[i]--;
                    }
                }


    }
    public static boolean contact(String a,String b){
        char s11[]=a.toCharArray();
        char s22[]=b.toCharArray();
            for (int j = 0; j < b.length()&&j<a.length(); j++) {
            if(s11[s11.length-1]==s22[j]){ 
                for (int k1 = s11.length-1,k2=j; k1 >=0&&k2>=0; k1--,k2--) {
                    if (s11[k1]!=s22[k2]){
                        return false;
                    }
                  if (k2==0) {
                        b=b.substring(j+1);
                        tmp=a+b;
                        return true;

                    }
                }
            }
        }   

        return false;
    }
    public static boolean checkString(String a,String b) {
        //相同的单词居然不算包含。。。快被玩坏了
        String a1;
        String b1;
        if (a.length()<=b.length()) {
            a1=a;
            b1=b;
        }
        else {
            a1=b;
            b1=a;
        }
        char a11[]=a1.toCharArray();
        char b11[]=b1.toCharArray();
        if (a1.equals(b1)) {
            return true;
        }
        for (int i = 0; i < a11.length; i++) {
            if (a11[i]!=b11[i]) {
                return true;
            }
        }
        return false;
    }
    public static boolean findS1(String a){
        char ss[]=a.toCharArray();
        if(ss[0]==st){
            s1=a;
        return true;
        }
        else {
            return false;
        }
    }

}

