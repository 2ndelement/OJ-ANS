import java.util.Scanner;


public class Main {
    public static void main(String[] args) {
        Scanner sn = new Scanner(System.in);
        int inputValue = sn.nextInt();
        System.out.println(new Main().lastRemaining(inputValue));
    }

    /**
     * @param n        ���鳤��
     * @param fromLeft ture �����ң�false���ҵ���
     * @return
     */
    public int recursion(int n, boolean fromLeft) {
        if (n == 1) return 1;
        if (fromLeft) {
            return 2 * recursion(n / 2, false);
        } else {
            if (n % 2 == 1) {
                return 2 * recursion(n / 2, true);
            } else {
                return 2 * recursion(n / 2, true) - 1;
            }
        }

    }

    public int lastRemaining(int n) {
        return recursion(n, true);
    }
}