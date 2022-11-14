import java.util.Scanner;

class Main {

    public int gcd(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }

    }

    public int nthMagicalNumber(int N, int A, int B) {
        int mod = 1000000007;
        int lcm = A * B / gcd(A, B);
        int left = 1, right = Integer.MAX_VALUE;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = mid / A + mid / B - mid / lcm;
            if (count < N) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left % mod;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        Main slt = new Main();
        int num = sc.nextInt();
        int div1 = sc.nextInt();
        int div2 = sc.nextInt();
        System.out.print(slt.nthMagicalNumber(num, div1, div2));

    }
}