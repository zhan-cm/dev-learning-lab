#定义全局变量money name
money=5000000
#要求客户输入姓名
name=input("请输入你的名字：")
#定义查询函数
def find(show):
    if show:
        print("--------------查询余额--------------")
    print(f"你好{name}，你的余额剩余{money}元")
#定义存款函数
def in_put(num):
    global money
    money+=num
    print("--------------存款--------------")
    print(f"你好{name},存款{num}元成功")
    find(False)
#定义取款函数
def out_put(num):
    global money
    money -= num
    print("--------------取款--------------")
    print(f"你好,取款{num}元成功")
    find(False)
def main():
    print("--------------主菜单--------------")
    print("你好，欢迎来到XX银行的ATM机，请选择操作")
    print("查询余额 [输入1]")
    print("存款    [输入2]")
    print("取款    [输入3]")
    print("退出    [输入4]")
    return input("请输入您的选择：")
while(True):
    keyboard_input = main()
    if keyboard_input=='1':
        find(True)
        continue
    elif keyboard_input == '2':
        num=int(input("要存多少钱？："))
        in_put(num)
        continue
    elif keyboard_input == '3':
        num=int(input("要取多少钱？："))
        out_put(num)
        continue
    else:
        print("程序退出")
        break