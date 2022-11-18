import java.util.*;

class Main {
    public List<String> getIpAddresses(String s) {
        List<String> result = new ArrayList<>();
        int len = s.length();
        if (len < 4 || len > 12) {
            return result;
        }

        for (int i = 1; i < 4; i++) {
            for (int j = 1; j < 4; j++) {
                for (int k = 1; k < 4; k++) {
                    for (int l = 1; l < 4; l++) {
                        if (i + j + k + l == len) {
                            int a = Integer.parseInt(s.substring(0, i));
                            int b = Integer.parseInt(s.substring(i, i + j));
                            int c = Integer.parseInt(s.substring(i + j, i + j + k));
                            int d = Integer.parseInt(s.substring(i + j + k));
                            if (a <= 255 && b <= 255 && c <= 255 && d <= 255) {
                                String ip = a + "." + b + "." + c + "." + d;
                                if (ip.length() == len + 3) {
                                    result.add(ip);
                                }
                            }
                        }
                    }
                }
            }
        }
        return result;

    }


    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        String str = sc.nextLine();

        Main slt = new Main();

        for (int i = 0; i < slt.getIpAddresses(str).size(); i++) {

            System.out.println(slt.getIpAddresses(str).get(i));

        }
    }
}