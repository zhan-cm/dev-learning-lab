package Regex_Exception;

public class Regular_Expression {
    //正则表达式
    //public boolean matches(String regex)  判断字符串是否匹配正则表达式

    /*
        正则表达式书写规则：
            字符类：只匹配单个字符
                [abc]   只能是a，b或c
                [^abc]  除了a，b或c以外的任何字符
                [a-zA-Z]    a到z A到Z
                [a-d[m-p]]  a到d或m到p
                [a-z&&[def]]    d，e或f（交集）
                [a-z&&[^bc]]    a到z，除了b和c
                [a-z&&[^m-p]]   a到z，除了m到p

            预定义字符：只能匹配单个字符
                .   任何字符
                \d  一个数字0-9
                \D  非数字^0-9
                \s  一个空白字符
                \S  非空白字符
                \w  [a-zA-Z_0-9]
                \W  一个非单词字符

            数量词：
                x?  一次或0次
                x*  零次或多次
                x+  一次或多次
                x{n}    正好n次
                x{n,}   至少n次
                x{n,m}  至少n但不超过m次
    */
}
