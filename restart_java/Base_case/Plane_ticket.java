package Base_case;

import java.util.Scanner;

public class Plane_ticket {
    /*
     * 需求：
     * 用户购买车票时，机票原价会按照淡季、旺季，头等舱还是经济舱的情况进行相应的优惠，
     * 优惠方案如下：
     * 5-10月为旺季，头等舱9折，经济舱8.5折；
     * 11-4月为淡季，头等舱7折，经济舱6.5折
     * 请计算用户当前机票的优惠价
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入当前月份(1-12):");
        int month = sc.nextInt();
        System.out.println("请输入当前原票价:");
        double price = sc.nextDouble();
        System.out.println("请问你是头等舱还是经济舱:");
        String site = sc.next();

        if(month>4&&month<11){
            if(site.equals("头等舱")){
                price=price*0.9;
                System.out.println("旺季头等舱9折，你的优惠价为:"+price);
            }else{
                price=price*0.85;
                System.out.println("旺季经济舱8.5折，你的优惠价为:"+price);
            }
        }else{
            if(site.equals("头等舱")){
                price=price*0.7;
                System.out.println("淡季头等舱7折，你的优惠价为:"+price);
            }else{
                price=price*0.65;
                System.out.println("淡季经济舱6.5折，你的优惠价为:"+price);
            }
        }
    }
}
