#打开文件，以读取模式打开
f=open("F:/test.txt","r",encoding="UTF-8")
#方式1：读取全部内容，通过字符串count方法统计itheima单词数量
#content=f.read()
#count=content.count("itheima")
#print(f"itheima在文件出现了：{count}次")
#方式2：读取内容，一行一行读取
#判断单词出现次数并且累计
count=0
for line in f:
    line =line.strip()
    words=line.split(" ")
    for word in words:
        if word=="itheima":
            count+=1
print(count)
#关闭文件
f.close()