num=5
if int(input("请输入第一次想猜的数字："))==num:
    print("恭喜你第一次就猜对了")
elif int(input("猜错了 ，再猜一次："))==num:
    print("猜对了")
elif int(input("猜错了 ，再猜一次："))==num:
    print("恭喜，最后一次机会，你猜对了")
else:
    print("可惜，你没有猜出来")