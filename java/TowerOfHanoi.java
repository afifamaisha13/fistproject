public class TowerOfHanoi {


    public static void hanoi(int n, String a, String b, String c) {
        if (n == 1) {
            System.out.println("Move disk 1 from " + a + " to " + c);
        } else {
            hanoi(n - 1, a, c, b);
            System.out.println("Move disk " + n + " from " + a + " to " + c);
            hanoi(n - 1, b, a, c);
        }

    }

    public static void main(String[] n) {
        int num = 4;
        String A = "A";
        String B = "B";
        String C = "C";
        hanoi(num,A,B,C);
    }
}
