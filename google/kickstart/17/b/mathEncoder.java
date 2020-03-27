/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package sport;

/**
 *
 * @author Chamal
 */
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.math.BigInteger;
import java.util.Scanner;

public class Sport {

    public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
        PrintWriter writer = new PrintWriter("2out.txt", "UTF-8");
        Scanner scanner = new Scanner(new File("2.txt"));
        int t = scanner.nextInt();
        for (int tt = 1; tt <= t; tt++) {
            int xx;
            BigInteger sum = new BigInteger("0");
            BigInteger temp, temp2, b1pow, dif;
            BigInteger b = new BigInteger("1");

            BigInteger b1 = new BigInteger("2");
            BigInteger b2 = new BigInteger("1000000007");
            int x, curIndex = 0;
            x = scanner.nextInt();
            int pdata[] = new int[x];
            for (int i = 0; i < x; i++) {
                pdata[i] = scanner.nextInt();
                b1pow = b1.pow(x - i - 1);
                b1pow = b1pow.subtract(b);
                temp = BigInteger.valueOf(pdata[i]).multiply(b1pow);
                b1pow = b1.pow(i);
                b1pow = b1pow.subtract(b);
                temp2 = BigInteger.valueOf(pdata[i]).multiply(b1pow);
                sum = sum.add(temp2);
                sum = sum.subtract(temp);
                sum = sum.mod(b2);
            }
            writer.println("Case #" + tt + ": " + sum);
        }
        writer.close();
    }
}
