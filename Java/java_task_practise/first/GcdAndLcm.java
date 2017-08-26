package com.company;

import java.util.Scanner;

public class GcdAndLcm {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        System.out.println("The GCD of " + a + " and " + b + " is " + gcd(a, b));
        System.out.println("The LCM of " + a + " and " + b + " is " + lcm(a, b));
    }

    public static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }


    public static int lcm(int a, int b) {
        return a * (b / gcd(a, b));
    }

}
