##### 查询
	查询所有数据库
		show databases;
	查询当前数据库
		select database();

##### 创建
	create database [if not exists] 数据库名 [default charset 字符集] [collate 排序规则];

##### 删除
	drop database [if exists] 数据库名;

##### 使用
	use 数据库名;