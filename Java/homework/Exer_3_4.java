package com.company;

public class Exer_3_4 {
    public static void main(String[] args) {
        int sum = 0;
        int temp = 1;
        int i = 1;
        while (i <= 20) {
            sum += temp;
            i++;
            temp *= i;
        }
        System.out.println(sum);
    }
}
