import java.util.*;

public class MagicSquareEven {
    public static void main(String[] args) {
    int n=4;
    int [][]a=new int[n][n];
    int num=1;
    int el=n*n;
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            if(row!=col && n-1-row!=col)
            a[row][col]=num;
            else{
                a[row][col]=el;
            }
            el--;
            num++;
        }
    }

    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            System.out.printf("%4d",a[row][col]);
        }
        System.out.println();
    }
}
}
