mylist=[1,2,3,4,5,6,7,8,9,10]
mylist1=[]
mylist2=[]
index1=0
while index1<len(mylist):
    num=mylist[index1]
    if num%2==0:
        mylist1.append(num)
    index1+=1
print(mylist1)
for num in mylist:
    if num%2==0:
        mylist2.append(num)
print(mylist2)