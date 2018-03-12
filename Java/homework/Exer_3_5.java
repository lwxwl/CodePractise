package com.company;

public class Exer_3_5 {
    public static void main(String[] args) {
        int i, j, k;
        for (i = 2; i < 100; i++) {
            k = (int) Math.sqrt(i);
            for (j = 2; j < 100; j++) {
                if (i % j == 0) {
                    break;
                }
            }
            if (j > k) {
                System.out.println(i);
            }
        }
    }
}
