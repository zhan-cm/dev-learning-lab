package Base_case;

import java.util.Random;
import java.util.Scanner;

public class Develop_CAPTCHA {
    //需求：开发一个程序，可以生生成指定位数验证码，每位可以是数字，大小写字母
    public static void main(String[] args) {
        char[] arr = {'1','2','3','4','5','6','7','8','9','0',
                'q','w','e','r','t','y','u','i','o','p','a','s',
                'd','f','g','h','j','k','l','z','x','c','v','b',
                'n','m','Q','W','E','R','T','Y','U','I','O','P',
                'A','S','D','F','F','G','H','J','K','L','Z','X',
                'C','V','B','N','M'};
        Scanner sc = new Scanner(System.in);
        Random r = new Random();
        System.out.println("请输入你想生成的验证码个数：");
        int number = sc.nextInt();
        String s = "";
        for (int i = 0; i < number; i++) {
            int index = r.nextInt(arr.length);
            s=s+arr[index];
        }
        System.out.println("验证码为："+s);
    }
}
