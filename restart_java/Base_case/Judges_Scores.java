package Base_case;

import java.util.Scanner;

public class Judges_Scores {
    //需求：在唱歌比赛中，可能有多名评委给选手打分，分数时0-100之间的整数。
    //选手最后得分为：去掉最高分和最低分后生下来分数的平均分。
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入有多少名评委：");
        int num = sc.nextInt();
        double[] scores = new double[num];
        for(int i=0;i<num;i++){
            System.out.println("请输入第"+(i+1)+"个评委的分数");
            double score = sc.nextDouble();
            scores[i] =score;
        }
        double max =scores[0];
        double min =scores[0];
        double total=0;
        for (int i = 0; i < num; i++) {
            if(scores[i]> max){
                max =scores[i];
            }
            if(scores[i]<min){
                min = scores[i];
            }
            total+=scores[i];
        }
        double result = (total-max-min)/num;
        System.out.println("最终得分为："+ result);
    }
}
