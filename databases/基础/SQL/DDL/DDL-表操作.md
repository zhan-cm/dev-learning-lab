
---
### 查询

##### 查询当前所有数据库所有表
	show tables;

##### 查询表结构
	desc 表名；

##### 查询指定表的建表语句
	show create table 表名;

---

### 创建
	create table 表名(
		字段1 字段1类型 [comment 字段1注释],
		字段2 字段2类型 [comment 字段2注释],
		字段3 字段3类型 [comment 字段3注释],
		...
		字段n 字段n类型 [comment 字段n注释]
	) [comment 表注释];

---

### 数据类型

![[img/14689.png]]

![[1489.png]]

![[7825.png]]

---

![[845.png]]

![[45689.png]]

---

### 修改

##### 添加字段
	alter table 表名 add 字段名 类型（长度）[comment 注释] [约束];

##### 修改数据类型
	alter table 表名 modify 字段名 新数据类型（长度）;

##### 修改字段名和字段类型
	alter table 表名 change 旧字段名 新字段名 类型（长度）[comment 注释] [约束];

##### 删除字段
	alter table 表名 drop 字段名;

##### 修改表名
	alter table 表名 rename to 新表名;

---

### 删除

##### 删除表
	drop table [if exists] 表名;
##### 删除指定表，并重新创建该表
	truncate table 表名;
