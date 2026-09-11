package IO_Stream;

public class IO_ {
    /*
                                     IO流体系
                                       ||
                              =====================
                              |                   |
                            字节流                字符流             抽象类
                         =============          =============
                         |           |          |           |
                     字节输入流  字节输出流       字符输入流   字符输出流       实现类
                  InputStream OutputStream     Reader       Writer
                   |                |             |            |
  原始流/低级流     FileInputStream  FileOutputStream   FileReader  FileWriter
  包装流/处理流     BufferedInputStream BufferedOutputStream BufferedReader BufferedWriter
                                                           InputStreamReader OutputStreamWriter
     */

}
