import java.util.*;

class Main {

    public List<List<Integer>> res;

    public List<List<Integer>> getFactors(int n) {
        res = new ArrayList<>();
        if (n <= 3) return res;
        List<Integer> path = new ArrayList<>();
        dfs(n, 2, path);
        return res;
    }

    private void dfs(int n, int i, List<Integer> path) {
        if (n == 1) {
            if (path.size() > 1) {
                res.add(new ArrayList<>(path));
            }
            return;
        }
        for (int j = i; j <= n; j++) {
            if (n % j == 0) {
                path.add(j);
                dfs(n / j, j, path);
                path.remove(path.size() - 1);
            }
        }
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        Main slt = new Main();
        for (int i = 0; i < slt.getFactors(num).size(); i++) {
            System.out.println(slt.getFactors(num).get(i));
        }
    }
}