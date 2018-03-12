package com.company;

public class Exer_3_9 {
    public static void main(String[] args) {
        double sum = 0;
        double temp = 1;
        int i = 1;
        while (true) {
            sum += temp;
            if (sum > 9999) {
                break;
            }
            i++;
            temp *= i;
        }
        System.out.println(i);
    }
}
