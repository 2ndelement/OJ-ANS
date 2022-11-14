import java.util.*;

class Main {

    public int maxUniqueSplit(String s) {
        return dfs(s, 0, new HashSet<>());
    }

    private int dfs(String s, int start, Set<String> set) {
        if (start == s.length()) return 0;
        int max = 0;
        for (int i = start; i < s.length(); i++) {
            String str = s.substring(start, i + 1);
            if (set.contains(str)) continue;
            set.add(str);
            max = Math.max(max, 1 + dfs(s, i + 1, set));
            set.remove(str);
        }
        return max;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        Main slt = new Main();
        System.out.print(slt.maxUniqueSplit(str));
    }
}