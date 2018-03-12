package com.company;

public class Exer_3_6 {
    public static void main(String[] args) {
        double temp = 1;
        double i = 1;
        double sum = 0;
        while (i <= 20) {
            sum += temp;
            i++;
            temp *= (1.0) / i;
        }
        System.out.println(sum);

        for (sum = 0, i = 1, temp = 1; i <= 20; i++) {
            temp *= (1.0) / i;
            sum += temp;
        }
        System.out.println(sum);
    }
}
