package Prepositive_Knowledge;

import java.io.File;

public class Method_recursion {
    /*
        递归的形式：
            直接递归：方法自己调用自己
            间接递归：方法调用其他方法，其他方法又回调方法自己
     */
    public static void main(String[] args) {
        searchFile(new File("C:/"),"QQ.exe");
    }
    public static void searchFile (File dir,String filename){
        //1.把非法的情况都拦截
        if(dir==null||!dir.exists()||dir.isFile()){
            return;
        }
        //2.dir不是null，存在，一定是目录对象
        //获取当前目录的全部一级文件对象
        File[] files = dir.listFiles();

        //3.判断当前目录下是否存在一级文件对象，以及是否可以拿到以及文件对象
        if(files!=null&& files.length>0){
            for(File f:files){
                //5.判断这个文件是文件还是文件夹
                if(f.isFile()){
                    //是文件，判断这个文件是否是我们要找的
                    if(f.getName().contains(filename)){
                        System.out.println("找到了"+f.getAbsolutePath());
                    }
                }else{
                    //是文件夹，继续重复这个过程（递归）
                    searchFile(f,filename);
                }
            }
        }
    }
}
