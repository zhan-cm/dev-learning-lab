info_dict={
    "wlh":{
        "部门":"科技部",
        "工资":3000,
        "级别":1
    },
    "zjl":{
        "部门":"市场部",
        "工资":5000,
        "级别":2
    },
    "ljj":{
        "部门":"市场部",
        "工资":7000,
        "级别":3
    },
    "zxy":{
    "部门":"科技部",
        "工资":4000,
        "级别":1
    },
    "ldh":{
    "部门":"市场部",
        "工资":6000,
        "级别":2
    }
}
#for循环遍历字典
for name in info_dict:
    if info_dict[name]["级别"]==1:
        employee_info_dict=info_dict[name]
        employee_info_dict["级别"]=2  #级别加一
        employee_info_dict["工资"]+=1000  #工资+1000
        info_dict[name]=employee_info_dict
print(f"对员工进行升职加薪后结果：{info_dict}")

    