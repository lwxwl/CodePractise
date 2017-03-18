/**
 * Created by Administrator on 2016/10/21.
 */
public class Test {
    public static void main(String[] args) {
        int c = 0;
        int a = 1;
        int b = 2;
        for (int i = 0; i < 3; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        System.out.println("c=" + c);
    }
}



