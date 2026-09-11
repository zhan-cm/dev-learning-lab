package Base_case.ATM;

import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class ATM {
    private ArrayList<Account> accounts = new ArrayList<>();
    Scanner sc = new Scanner(System.in);
    private String number = "0123456789";
    Random r = new Random();

    public void start() {
        while (true) {
            System.out.println("==欢迎进入我的银行ATM系统==");
            System.out.println("1、用户登录");
            System.out.println("2、用户开户");
            System.out.println("请输入你要操作的命令：");
            int command = sc.nextInt();
            switch (command) {
                case 1:
                    Login();
                    break;
                case 2:
                    Register();
                    break;
                default:
                    System.out.println("无效命令");
            }
        }
    }

    private void Register() {
        Account account = new Account();

        System.out.println("==系统开户操作==");

        System.out.println("请输入账户用户名：");
        String accountName = sc.next();
        account.setName(accountName);

        while (true) {
            System.out.println("请输入你的性别：");
            char sex = sc.next().charAt(0);
            if(sex=='男'||sex=='女'){
                account.setSex(sex);
                break;
            }else{
                System.out.println("性别输入异常，请重新输入");
            }
        }
        while (true) {
            System.out.println("请输入你的账户密码：");
            String password = sc.next();
            System.out.println("请输入你的确认密码：");
            String RePassword = sc.next();
            if(password.equals(RePassword)){
                account.setPassword(password);
                break;
            }else {
                System.out.println("两次输入的密码不一致，请重新输入");
            }
        }

        System.out.println("请输入你每次取现限额：");
        double limitMoney = sc.nextDouble();
        account.setLimitTransaction(limitMoney);

        String cardId = "";
        for (int i = 0; i < 8; i++) {
            int RandNum = r.nextInt(number.length());
            cardId += number.charAt(RandNum);
        }
        System.out.println("恭喜你，"+accountName+"先生,你开户成功，你的卡号是："+cardId);
        account.setId(cardId);


        accounts.add(account);
    }

    private void Login(){
        System.out.println("==系统登录操作==");
        System.out.println("请输入登录卡号：");
        if(accounts.size()==0){
            System.out.println("当前系统无该账户信息，请先开户");
            return;
        }

        while (true) {
            System.out.println("请您输入你的登录卡号");
            String cardId = sc.next();
            Account acc = getAccountByCardId(cardId);
            if(acc==null){
                System.out.println("输入的卡号不存在");
            }else{
                while (true) {
                    System.out.println("请输入登录密码：");
                    String password = sc.next();
                    if(acc.getPassword().equals(password)){
                        System.out.println("恭喜你，"+acc.getName()+"，成功登录了系统，你的卡号是："+acc.getId());

                    }else{
                        System.out.println("输入的密码错误，重新输入");
                    }
                }
            }
        }
    }

    private void showUserCommand(){
        System.out.println("您可以选择如下功能进行账户的处理===");
    }

    private Account getAccountByCardId(String cardId){
        for(int i=0;i<accounts.size();i++){
            Account acc = accounts.get(i);

            if(acc.getId().equals(cardId)){
                return acc;
            }
        }
        return null;
    }
}
