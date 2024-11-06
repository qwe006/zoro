mysql> show databases;
+--------------------+
| Database           |
+--------------------+
| company            |
| diva               |
| employee           |
| information_schema |
| my_company         |
| mysql              |
| performance_schema |
| sys                |
| te_a2_22           |
| te_b25             |
| te_b_25            |
+--------------------+
11 rows in set (0.01 sec)
mysql> create database first;
Query OK, 1 row affected (0.01 sec)
mysql> show databases;
+--------------------+
| Database           |
+--------------------+
| company            |
| diva               |
| employee           |
| first              |
| information_schema |
| my_company         |
| mysql              |
| performance_schema |
| sys                |
| te_a2_22           |
| te_b25             |
| te_b_25            |
+--------------------+
12 rows in set (0.00 sec)

mysql> use first;
Database changed

mysql> create table student(roll_no int(10) primary key,name varchar(20),address varchar(32));
Query OK, 0 rows affected, 1 warning (0.02 sec)

mysql> desc student;
+---------+-------------+------+-----+---------+-------+
| Field   | Type        | Null | Key | Default | Extra |
+---------+-------------+------+-----+---------+-------+
| roll_no | int         | NO   | PRI | NULL    |       |
| name    | varchar(20) | YES  |     | NULL    |       |
| address | varchar(32) | YES  |     | NULL    |       |
+---------+-------------+------+-----+---------+-------+
3 rows in set (0.01 sec)


mysql> select *from student;
+---------+-------+---------+
| roll_no | name  | address |
+---------+-------+---------+
|       1 | radha | pune    |
+---------+-------+---------+
1 row in set (0.00 sec)

mysql> insert into student (roll_no,name,address)
    -> values(2,'ram','mumbai'),
    -> (3,'kanha','kanpur');
Query OK, 2 rows affected (0.00 sec)
Records: 2  Duplicates: 0  Warnings: 0

mysql> select *from student;
+---------+-------+---------+
| roll_no | name  | address |
+---------+-------+---------+
|       1 | radha | pune    |
|       2 | ram   | mumbai  |
|       3 | kanha | kanpur  |
+---------+-------+---------+
3 rows in set (0.00 sec)

mysql> alter table student add phone int;
Query OK, 0 rows affected (0.01 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> select*from student;
+---------+-------+---------+-------+
| roll_no | name  | address | phone |
+---------+-------+---------+-------+
|       1 | radha | pune    |  NULL |
|       2 | ram   | mumbai  |  NULL |
|       3 | kanha | kanpur  |  NULL |
+---------+-------+---------+-------+
3 rows in set (0.00 sec)
mysql> update student set phone=123 where roll_no=1;
Query OK, 1 row affected (0.01 sec)
Rows matched: 1  Changed: 1  Warnings: 0

mysql> select * fromt student;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'fromt student' at line 1
mysql> select *from student;
+---------+-------+---------+-------+
| roll_no | name  | address | phone |
+---------+-------+---------+-------+
|       1 | radha | pune    |   123 |
|       2 | ram   | mumbai  |  NULL |
|       3 | kanha | kanpur  |  NULL |
+---------+-------+---------+-------+
3 rows in set (0.00 sec)

mysql>  update student set phone=123456 where roll_no=2;
Query OK, 1 row affected (0.00 sec)
Rows matched: 1  Changed: 1  Warnings: 0

mysql> select *from student;
+---------+-------+---------+--------+
| roll_no | name  | address | phone  |
+---------+-------+---------+--------+
|       1 | radha | pune    |    123 |
|       2 | ram   | mumbai  | 123456 |
|       3 | kanha | kanpur  |   NULL |
+---------+-------+---------+--------+
3 rows in set (0.00 sec)

mysql>  update student set phone=12376348 where roll_no=3;
Query OK, 1 row affected (0.00 sec)
Rows matched: 1  Changed: 1  Warnings: 0

mysql> select *from student;
+---------+-------+---------+----------+
| roll_no | name  | address | phone    |
+---------+-------+---------+----------+
|       1 | radha | pune    |      123 |
|       2 | ram   | mumbai  |   123456 |
|       3 | kanha | kanpur  | 12376348 |
+---------+-------+---------+----------+
3 rows in set (0.00 sec)

mysql> insert into student (roll_no,name,address,phone)values(4,'abd','wagholi',9865),(5,'rty','pune',8765654),(6,'juyt','mumbai',54322);
Query OK, 3 rows affected (0.00 sec)
Records: 3  Duplicates: 0  Warnings: 0

mysql> select*from student;
+---------+-------+---------+----------+
| roll_no | name  | address | phone    |
+---------+-------+---------+----------+
|       1 | radha | pune    |      123 |
|       2 | ram   | mumbai  |   123456 |
|       3 | kanha | kanpur  | 12376348 |
|       4 | abd   | wagholi |     9865 |
|       5 | rty   | pune    |  8765654 |
|       6 | juyt  | mumbai  |    54322 |
+---------+-------+---------+----------+
6 rows in set (0.00 sec)

mysql> select *from student where address='mumbai';
+---------+------+---------+--------+
| roll_no | name | address | phone  |
+---------+------+---------+--------+
|       2 | ram  | mumbai  | 123456 |
|       6 | juyt | mumbai  |  54322 |
+---------+------+---------+--------+
2 rows in set (0.00 sec)

mysql> select address from student ;
+---------+
| address |
+---------+
| pune    |
| mumbai  |
| kanpur  |
| wagholi |
| pune    |
| mumbai  |
+---------+
6 rows in set (0.00 sec)

mysql> update student set name ='raju' where roll_no=2;
Query OK, 1 row affected (0.00 sec)
Rows matched: 1  Changed: 1  Warnings: 0

mysql> select *from student;
+---------+-------+---------+----------+
| roll_no | name  | address | phone    |
+---------+-------+---------+----------+
|       1 | radha | pune    |      123 |
|       2 | raju  | mumbai  |   123456 |
|       3 | kanha | kanpur  | 12376348 |
|       4 | abd   | wagholi |     9865 |
|       5 | rty   | pune    |  8765654 |
|       6 | juyt  | mumbai  |    54322 |
+---------+-------+---------+----------+
