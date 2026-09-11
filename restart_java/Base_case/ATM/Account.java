package Base_case.ATM;

public class Account {
    private String id;
    private String name;
    private char sex;
    private String password;
    private double balance;
    private  double limitTransaction;


    public Account() {
    }

    public Account(String id, String name, char sex, String password, double balance, double limitTransaction) {
        this.id = id;
        this.name = name;
        this.sex = sex;
        this.password = password;
        this.balance = balance;
        this.limitTransaction = limitTransaction;
    }

    /**
     * 获取
     * @return id
     */
    public String getId() {
        return id;
    }

    /**
     * 设置
     * @param id
     */
    public void setId(String id) {
        this.id = id;
    }

    /**
     * 获取
     * @return name
     */
    public String getName() {
        return name;
    }

    /**
     * 设置
     * @param name
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * 获取
     * @return sex
     */
    public char getSex() {
        return sex;
    }

    /**
     * 设置
     * @param sex
     */
    public void setSex(char sex) {
        this.sex = sex;
    }

    /**
     * 获取
     * @return password
     */
    public String getPassword() {
        return password;
    }

    /**
     * 设置
     * @param password
     */
    public void setPassword(String password) {
        this.password = password;
    }

    /**
     * 获取
     * @return balance
     */
    public double getBalance() {
        return balance;
    }

    /**
     * 设置
     * @param balance
     */
    public void setBalance(double balance) {
        this.balance = balance;
    }

    /**
     * 获取
     * @return limitTransaction
     */
    public double getLimitTransaction() {
        return limitTransaction;
    }

    /**
     * 设置
     * @param limitTransaction
     */
    public void setLimitTransaction(double limitTransaction) {
        this.limitTransaction = limitTransaction;
    }

    public String toString() {
        return "Account{id = " + id + ", name = " + name + ", sex = " + sex + ", password = " + password + ", balance = " + balance + ", limitTransaction = " + limitTransaction + "}";
    }
}
