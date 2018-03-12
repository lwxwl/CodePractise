package com.company;

import java.util.Scanner;

public class Exer_3_8 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        if (a < b) {
            int temp = a;
            a = b;
            b = temp;
        }
        System.out.println(gcd(a, b) + " " + lcm(a, b));

    }

    public static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    public static int lcm(int a, int b) {
        return a * (b / gcd(a, b));
    }
}
