package com.company;

public class Exer_3_7 {
    public static void main(String[] args) {
        int sum, i, j;
        for (i = 1; i <= 1000; i++) {
            for (j = 1, sum = 0; j < i; j++) {
                if (i % j == 0) {
                    sum += j;
                }
            }
            if (sum == i) {
                System.out.print(i + " ");
            }
        }
    }
}
