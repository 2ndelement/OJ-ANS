import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class Main {
    private static Map<String, Boolean> map = new HashMap<>();

    public static boolean canWin(String str) {
        if (map.containsKey(str)) {
            return map.get(str);
        }
        for (int i = 0; i + 1 < str.length(); i++) {
            if (str.charAt(i) == '+' && str.charAt(i + 1) == '+') {
                String changedStr = str.substring(0, i) + "--" + str.substring(i + 2);
                if (canWin(changedStr)) {
                    map.put(changedStr, true);
                } else {
                    map.put(changedStr, false);
                    return true;
                }
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        System.out.println(canWin(str));
    }
}