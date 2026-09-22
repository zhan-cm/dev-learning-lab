total=10000
for i in range(1,21):
    import random
    score = random.randint(1, 10)
    if score>=5:
        if total>=1000:
            total=total-1000
            print(f"向员工{i}发放工资1000元，账户余额还剩{total}元")
        else:
            print("发完了")
            break
    else:
        print(f"员工{i},绩效分{score},低于5，不发工资，下一个")