import java.util.Scanner;
public class MagicSquare {
    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);
        System.out.print("Enter the size of the magic square for odd number: ");
        int n=sc.nextInt();

        if (n%2==0) {
            System.out.println("The size must be an odd number!");
            return;
        }

        int[][]a = new int[n][n];

        // Initial position of 1
        int row = n / 2;
        int col = n - 1;

        for (int num = 1; num <= n * n; ) {
            if (row == -1 && col == n) {
                row = 0;
                col = n - 2;
            } else {
                if (row < 0) {
                    row = n - 1;
                }
                if (col == n) {
                    col = 0;
                }
            }

            if (a[row][col] != 0) {
                row += 1;
                col -= 2;
                continue;
            } else {
                a[row][col] = num++;
            }

            row--;
            col++;
        }

        System.out.println("The Magic Square of size " + n + ":");
        for (row = 0; row < n; row++) {
            for (col = 0; col < n; col++)
                System.out.printf("%5d", a[row][col]);
            System.out.println();
        }
    }
}
