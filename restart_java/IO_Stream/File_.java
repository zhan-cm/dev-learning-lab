package IO_Stream;

public class File_ {
    /*
        构造器：
            public File(String pathname)    根据文件路径创建文件对象
            public File(String parent,String child)    根据父路径和子路径名字创建文件对象
            public File(File parent,String child)   根据父路径对应文件对象和子路径名字创建文件对象
     */
    /*
        File提供的判断文件类型，获取文件信息功能
        boolean exists()    对应的文件路径是否存在
        boolean isFile()    当前文件对象是否为文件
        boolean isDirectory()   当前文件对象是否为文件夹
        String getName()    获取文件名称（包含后缀）
        long length()   获取文件大小，返回字节个数
        long lastModified() 获取问及那最后修改时间
        String getPath()    获取创建文件对象时，使用的路径
        String getAbsolutePath()    获取绝对路径
     */
    /*
        File创建文件和删除文件的相关方法：
            boolean createNewFile() 创建一个新文件（文件内容为空），创建成功返回true
            boolean mkdir() 用于创建文件夹，注意：只能创建一级文件夹
            boolean mkdirs()    用于创建文件夹，注意：可以创建多级文件夹
            boolean delete()    删除文件，或者空文件夹，注意：不能删除非空文件夹
     */
    /*
        遍历文件夹：
            public String[] list()  获取当前目录下所有的“一级文件名称”到一个字符串数组中去
            public File[] listFiles()   获取当前目录下所有的“一级文件对象”到一个文件对象数组中去返回
                使用listFile方法时的注意事项：
                    当主调时文件，或者路径不存在时，返回null
                    当主调时空文件夹时，返回一个长度为0的数组
                    当主调是一个有内容的文件夹时，将里面所有的一级文件和文件夹的路径放在File数组中返回
                    当主调是一个文件夹，且里面有隐藏文件时，将里面所有文件和文件夹的路径放在File数组中返回，包含隐藏文件
                    当主调是一个文件夹，但是没有权限访问该文件夹时，返回null
     */
}
