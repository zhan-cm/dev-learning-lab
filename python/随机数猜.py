import random
num = random.randint(1,10)
guess=int(input("输入："))
if guess==num:
    print("猜对了")
else:
    if guess>num:
        print("猜大了")
    elif guess<num:
        print("猜小了")
    guess=int(input("再猜："))
    if guess == num:
        print("第二次猜对了")
    else:
        if guess > num:
            print("猜大了")
        elif guess < num:
            print("猜小了")
        guess = int(input("最后一次猜："))
        if guess == num:
            print("第三次猜对了")
        else:
            print("没机会了")