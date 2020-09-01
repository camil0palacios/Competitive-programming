import java.util.*;

class shirts {

    public static String t;
    public static int n;
    public static String [] a;
    public static byte[] dp;

    public static void main(String [] args) {
        Scanner stdin = new Scanner(System.in);
        t = stdin.next();
        n = stdin.nextInt();
        a = new String[n]; 
        for(int i = 0; i < n; i++) {
            a[i] = stdin.next();
        }
        dp = new byte[1 << (n + 2)];
        Arrays.fill(dp, (byte) -1);
        System.out.println(Dp(0, 0));
    }

    public static int Dp(int idx, int msk) {
        if(idx == t.length()) return 1;
        if(dp[msk] != -1) return dp[msk];
        if((msk >> n) == 0 && t.charAt(idx) != '0') {
            int ans = Dp(idx + 1, msk | (1 << n));
            if(ans == 0 && idx + 2 <= t.length()) ans = Dp(idx + 2, msk | (1 << (n + 1)));
            if(ans == 1) return dp[msk] = 1;
        }
        for(int i = 0; i < n; i++) {
            if(((msk >> i) & 1) == 0 && match(a[i], t, idx)) {
                int ans = Dp(idx + a[i].length(), msk | (1 << i));
                if(ans == 1) return dp[msk] = 1;
            }
        }
        return dp[msk] = 0;
    }

    public static boolean match(String a, String b, int idx) {
        if(idx + a.length() > b.length()) return false;
        for(int i = 0, j = idx; i < a.length(); i++, j++) {
            if(a.charAt(i) != b.charAt(j)) return false;
        }
        return true;
    }
}