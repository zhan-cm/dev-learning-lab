package Prepositive_Knowledge;

public class CharSet {
    /*
        ASCII只有英文、数字、符号等，占用一个字节
        GBK中一个中文字符编码成连个字节的形式存储，其他为一字节
        UTF-8中汉字字符占用3个字节，其他为1字节
        --------------------------------
        编码：将字符按照指定字符集编码成字节
        解码：把字节按照指定字符集解码成字符

        java代码完成对字符的编码
        byte[] getBytes()   使用平台的默认字符集将该String编码成一系列字节，将结果存储到新字节数组中
        byte[] getBytes(String charsetName) 使用指定字符集将该String编码成一系列字节，将结果存储到新的字节数组中

        java代码完成对字符的解码
        String(byte[] bytes)    通过使用平台的默认字符集解码指定的字节数组来构造新的String
        String(byte[] bytes,String charsetName) 通过指定的字符集解码指定的字节数组来构造新的String
     */
}
