import java.util.Scanner;

class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        long num = sc.nextLong();
        System.out.println(isPower4(num));

    }

    public static boolean isPower4(long num) {
        if (num == 0) {
            return false;
        }
        while (num != 1) {
            if (num % 4 != 0) {
                return false;
            }
            num = num / 4;
        }
        return true;
    }
}