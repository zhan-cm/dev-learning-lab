package Multithreading.Thread_Security;

public class Account {
    private double money;
    private String cardId;

    public Account() {
    }

    public Account(double money, String cardId) {
        this.money = money;
        this.cardId = cardId;
    }

    /**
     * 获取
     * @return money
     */
    public double getMoney() {
        return money;
    }

    /**
     * 设置
     * @param money
     */
    public void setMoney(double money) {
        this.money = money;
    }

    /**
     * 获取
     * @return cardId
     */
    public String getCardId() {
        return cardId;
    }

    /**
     * 设置
     * @param cardId
     */
    public void setCardId(String cardId) {
        this.cardId = cardId;
    }

    public String toString() {
        return "Account{money = " + money + ", cardId = " + cardId + "}";
    }

    public void drawMoney(double money) {
        String name = Thread.currentThread().getName();

        if(this.money>=money){
            System.out.println(name+"取款成功");
        }else{
            System.out.println("余额不足");
        }
    }
}
