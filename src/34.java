import java.util.Scanner;

class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        String[] arr = str.split(" ");
        int[] a = new int[arr.length];
        for (int i = 0; i < a.length; i++) {
            a[i] = Integer.parseInt(arr[i]);
        }
        int lower = sc.nextInt();
        int upper = sc.nextInt();
        int res = 0;
        for (int i = 1; i <= a.length; i++) {
            for (int j = 0; j < a.length; j++) {
                if (j + i > a.length) break;
                int tmp = 0;
                for (int k = j; k < j + i; k++) {
                    tmp += a[k];
                }
                if (tmp >= lower && tmp <= upper) res++;
            }
        }
        System.out.println(res);
    }
}