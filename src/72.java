import java.util.*;


class Main {
    public void qsort(int[] arr) {
        qsort(arr, 0, arr.length - 1);

    }

    public void qsort(int[] arr, int start, int end) {
        if (start >= end) {
            return;
        }
        int pivot = arr[start];
        int i = start;
        int j = end;
        while (i < j) {
            while (i < j && arr[j] <= pivot) {
                j--;
            }
            if (i < j) {
                arr[i] = arr[j];
                i++;
            }
            while (i < j && arr[i] >= pivot) {
                i++;
            }
            if (i < j) {
                arr[j] = arr[i];
                j--;
            }
        }
        arr[i] = pivot;
        qsort(arr, start, i - 1);
        qsort(arr, i + 1, end);
    }

    public int minCost(int[] cost) {
        qsort(cost);
        int answer = 0;
        for (int i = 0; i < cost.length; i++) {
            if ((i + 1) % 3 == 0) continue;
            answer += cost[i];
        }
        return answer;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] cost = new int[n];
        for (int i = 0; i < n; i++) {
            cost[i] = sc.nextInt();
        }
        System.out.println(new Main().minCost(cost));
    }
}