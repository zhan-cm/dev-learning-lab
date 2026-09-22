import random
num = random.randint(1,100)
count=0
flag=True
while flag:
    guess=int(input("输入："))
    count+=1
    if guess==num:
        print("对了")
        flag=False
    else:
        if guess> num:
            print("大了")
        else:
            print("小了")

print(f"一共猜了{count}次")
