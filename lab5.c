mysql> select DName,count(*) from Employee,Department where DNo=Dnumber group by DName having (AVG(Salary)>30000);
+----------------+----------+
| DName          | count(*) |
+----------------+----------+
| ADMINISTRATION |        4 |
| HEADQUARTERS   |        1 |
| RESEARCH       |        5 |
+----------------+----------+
3 rows in set (0.05 sec)

mysql> select DName,count(*) as No_MALE from Employee E,Department D where E.DNo=D.Dnumber AND E.Sex="M" group by DName having E.Salary>30000;
ERROR 1054 (42S22): Unknown column 'E.Salary' in 'having clause'
mysql> select DName,count(*) as No_MALE from Employee E,Department D where E.DNo=D.Dnumber AND E.Sex="M" AND E.Salary>30000 group by DName;
+----------+---------+
| DName    | No_MALE |
+----------+---------+
| RESEARCH |       3 |
+----------+---------+
1 row in set (0.00 sec)

mysql> select E.FName,E.Minit,E.LName from Employee E where E.DNo in (select S.DNo from Employee S where S.Salary= (select MAX(M.Salary) from Employee M));
+----------+-------+------------+
| FName    | Minit | LName      |
+----------+-------+------------+
| ARAVINDH | P     | PARANAN    |
| VINANTHI | S     | REDDY      |
| VISHAL   | P     | MAHESWARAN |
| AISHU    | V     | VENKY      |
| SANTHOSH | G     | VARUN      |
+----------+-------+------------+
5 rows in set (0.01 sec)

mysql> select E.FName,E.Minit,E.LName from Employee E,Employee S,Employee SS where E.Superssn=S.Ssn and S.Superssn=SS.Ssn and SS.Ssn="886665555";
Empty set (0.04 sec)

mysql> select E.FName,E.Minit,E.LName from Employee E,Employee S,Employee SS where E.Superssn=S.Ssn and S.Superssn=SS.Ssn and SS.Ssn="333445555";
+----------+-------+------------+
| FName    | Minit | LName      |
+----------+-------+------------+
| VINANTHI | S     | REDDY      |
| VISHAL   | P     | MAHESWARAN |
| RAMESH   | K     | NARAYAN    |
+----------+-------+------------+
3 rows in set (0.00 sec)

mysql> select E.FName,E.Minit,E.LName from Employee E where (E.Salary-10000)>=(select MIN(S.Salary) from Employee S);
+----------+-------+------------+
| FName    | Minit | LName      |
+----------+-------+------------+
| ARAVINDH | P     | PARANAN    |
| VINANTHI | S     | REDDY      |
| VISHAL   | P     | MAHESWARAN |
| PRIYA    | R     | DHARSHINI  |
| SANTHOSH | G     | VARUN      |
| RAMESH   | K     | NARAYAN    |
| NAVYA    | V     | RAKESH     |
| VINITHA  | M     | MAHESH     |
+----------+-------+------------+
8 rows in set (0.00 sec)

mysql> select E.FName,E.Minit,E.LName from Employee E,WorksOn W where W.Essn=E.Ssn and W.Hours>5 and W.PNo=(select p.PNumber from Project p where p.PName="PRODUCTX");
+----------+-------+-----------+
| FName    | Minit | LName     |
+----------+-------+-----------+
| ARAVINDH | P     | PARANAN   |
| PRIYA    | R     | DHARSHINI |
+----------+-------+-----------+
2 rows in set (0.00 sec)

mysql> select E.FName,E.Minit,E.LName from Employee E,WorksOn W where W.Essn=E.Ssn and W.Hours>10 and W.PNo=(select p.PNumber from Project p where p.PName="PRODUCTX");
+----------+-------+-----------+
| FName    | Minit | LName     |
+----------+-------+-----------+
| ARAVINDH | P     | PARANAN   |
| PRIYA    | R     | DHARSHINI |
+----------+-------+-----------+
2 rows in set (0.00 sec)

mysql> select E.FName,E.Minit,E.LName from Employee E,Dependent D where E.FName=D.DependentName;
Empty set (0.00 sec)

mysql> select E.FName,E.Minit,E.LName from Employee E where E.Superssn=(select S.Ssn from Employee S where CONCAT(S.FName," ",S.LName)="VISHAL MAHESWARAN");
+-----------+-------+---------+
| FName     | Minit | LName   |
+-----------+-------+---------+
| ARAVINDH  | P     | PARANAN |
| AISHU     | V     | VENKY   |
| SANTHOSH  | G     | VARUN   |
| HARSHITHA | M     | REDDY   |
+-----------+-------+---------+
4 rows in set (0.01 sec)

mysql> create table Employee_Backup like Employee;
Query OK, 0 rows affected (0.32 sec)

mysql> show tables;
+-------------------+
| Tables_in_COMPANY |
+-------------------+
| Department        |
| Dependent         |
| DeptLocations     |
| Employee          |
| Employee_Backup   |
| Project           |
| WorksOn           |
+-------------------+
7 rows in set (0.00 sec)

mysql> select * from Employee_Backup;
Empty set (0.00 sec)

mysql> create table employee_backup select * from Employee;
Query OK, 10 rows affected (0.35 sec)
Records: 10  Duplicates: 0  Warnings: 0

mysql> show tables;
+-------------------+
| Tables_in_COMPANY |
+-------------------+
| Department        |
| Dependent         |
| DeptLocations     |
| Employee          |
| Employee_Backup   |
| Project           |
| WorksOn           |
| employee_backup   |
+-------------------+
8 rows in set (0.00 sec)

mysql> select * from employee_backup;
+-----------+-------+------------+-----------+------------+---------------------------+------+----------+-----------+-----+
| FName     | Minit | LName      | Ssn       | Bdate      | Address                   | Sex  | Salary   | Superssn  | DNo |
+-----------+-------+------------+-----------+------------+---------------------------+------+----------+-----------+-----+
| ARAVINDH  | P     | PARANAN    | 123456789 | 1997-09-17 | 123 MYLAPORE,CHENNAI,TN   | M    | 70000.00 | 333445555 |   5 |
| VINANTHI  | S     | REDDY      | 234567891 | 1998-06-02 | 389 SAIDAPET,CHENNAI,TN   | F    | 85000.00 | 888665555 |   5 |
| VISHAL    | P     | MAHESWARAN | 333445555 | 1995-12-25 | 321 ALWARPET,CHENNAI,TN   | M    | 60000.00 | 888665555 |   5 |
| PRIYA     | R     | DHARSHINI  | 345678912 | 1998-09-01 | 654 ROYAPETTAH,CHENNAI,TN | F    | 75000.00 | 987654321 |   4 |
| AISHU     | V     | VENKY      | 453453453 | 1992-11-25 | 789 MOGAPPAIR,CHENNAI,TN  | F    | 30000.00 | 333445555 |   5 |
| SANTHOSH  | G     | VARUN      | 666884444 | 2000-11-15 | 369 MAMBAKKAM,CHENNAI,TN  | M    | 40000.00 | 333445555 |   5 |
| HARSHITHA | M     | REDDY      | 888665555 | 1989-11-20 | 456 KANDIGAI,CHENNAI,TN   | F    | 35000.00 | 333445555 |   1 |
| RAMESH    | K     | NARAYAN    | 987654321 | 1997-04-19 | 356 TNAGAR,CHENNAI,TN     | F    | 45000.00 | 888665555 |   4 |
| NAVYA     | V     | RAKESH     | 987987987 | 1996-10-30 | 975 BESSI,CHENNAI,TN      | F    | 80000.00 | 987654321 |   4 |
| VINITHA   | M     | MAHESH     | 999887777 | 1998-09-14 | 453 ADYAR,CHENNAI,TN      | F    | 65000.00 | 987654321 |   4 |
+-----------+-------+------------+-----------+------------+---------------------------+------+----------+-----------+-----+
10 rows in set (0.00 sec)

mysql> select E.FName,E.LName from Employee E,WorksOn W where E.Ssn=W.Essn and W.PNo in (select P.PNumber from Project P where P.DNum =5);
+----------+-----------+
| FName    | LName     |
+----------+-----------+
| ARAVINDH | PARANAN   |
| PRIYA    | DHARSHINI |
| NAVYA    | RAKESH    |
| VINITHA  | MAHESH    |
+----------+-----------+
4 rows in set (0.00 sec)

mysql> select P.PName,SUM(W.Hours) from Project P,WorksOn W where P.PNumber=W.PNo group by P.PNumber;
+-----------------+--------------+
| PName           | SUM(W.Hours) |
+-----------------+--------------+
| PRODUCTX        |         52.5 |
| PRODUCTY        |         36.5 |
| PRODUCTZ        |         50.0 |
| COMPUTERIZATION |         30.0 |
| REORGANIZATION  |         40.0 |
+-----------------+--------------+
5 rows in set (0.00 sec)

mysql> select E.FName,E.LName from Employee E,WorksOn W where E.Ssn=W.Essn and W.PNo in (select P.PNumber from Project P);
+-----------+------------+
| FName     | LName      |
+-----------+------------+
| VISHAL    | MAHESWARAN |
| HARSHITHA | REDDY      |
| VINANTHI  | REDDY      |
| AISHU     | VENKY      |
| SANTHOSH  | VARUN      |
| RAMESH    | NARAYAN    |
| ARAVINDH  | PARANAN    |
| PRIYA     | DHARSHINI  |
| NAVYA     | RAKESH     |
| VINITHA   | MAHESH     |
+-----------+------------+
10 rows in set (0.00 sec)

Query 12:
mysql> select FName,LName from Employee,WorksOn where Essn=Ssn group by Ssn having count(PNo)=(select count(PNumber) from Project);
Empty set (0.36 sec)

mysql> select E.FName,E.LName from Employee E where E.Ssn not in (select W.Essn from WorksOn W);
Empty set (0.01 sec)

mysql> select AVG(Salary) from Employee where Sex="F";
+--------------+
| AVG(Salary)  |
+--------------+
| 59285.714286 |
+--------------+
1 row in set (0.00 sec)

mysql> select E.LName from Employee E,Department D where E.Ssn=D.Mgr_ssn and D.Mgr_ssn not in (select d.Essn from Dependent d);
+-------+
| LName |
+-------+
| REDDY |
+-------+
1 row in set (0.00 sec)

mysql> select E.FName,E.LName,E.Address from Employee E,WorksOn W,Project p where E.Ssn=W.Essn and W.PNo in(select P.PNumber from Project P where P.PLocation like "%CHENNAI%") and p.DNum not in (select D.DNumber from DeptLocations  D where D.DLocation like "%CHENNAI%");
Empty set (0.00 sec)

mysql> select E.FName,E.LName from Employee E,Employee S,Employee SS where E.Superssn=S.Ssn and S.Superssn=SS.Ssn and SS.LName="MAHESWARAN";
+----------+------------+
| FName    | LName      |
+----------+------------+
| VINANTHI | REDDY      |
| VISHAL   | MAHESWARAN |
| RAMESH   | NARAYAN    |
+----------+------------+
3 rows in set (0.00 sec)

mysql> select E.FName,E.LName from Employee E,WorksOn W where E.Ssn=W.Essn and W.PNo in (select P.PNumber from Project P where P.DNum=5);
+----------+-----------+
| FName    | LName     |
+----------+-----------+
| ARAVINDH | PARANAN   |
| PRIYA    | DHARSHINI |
| NAVYA    | RAKESH    |
| VINITHA  | MAHESH    |
+----------+-----------+
4 rows in set (0.00 sec)

mysql> select E.FName,E.LName from Employee E,WorksOn W where E.Ssn=W.Essn and W.PNo in (select P.PNumber from Project P where P.DNum=4);
+----------+---------+
| FName    | LName   |
+----------+---------+
| VINANTHI | REDDY   |
| AISHU    | VENKY   |
| SANTHOSH | VARUN   |
| RAMESH   | NARAYAN |
+----------+---------+
4 rows in set (0.00 sec)

mysql> select E.FName,E.LName from Employee E,WorksOn W where E.Ssn=W.Essn and W.PNo in (select P.PNumber from Project P where P.DNum=1);
+-----------+------------+
| FName     | LName      |
+-----------+------------+
| VISHAL    | MAHESWARAN |
| HARSHITHA | REDDY      |
+-----------+------------+
2 rows in set (0.00 sec)

mysql> select E.FName,E.LName,D.DependentName from Employee E,Dependent D where E.Sex="F" and D.Essn=E.Ssn;
+--------+---------+---------------+
| FName  | LName   | DependentName |
+--------+---------+---------------+
| RAMESH | NARAYAN | ABNER         |
+--------+---------+---------------+
1 row in set (0.00 sec)

mysql>  select distinct Ssn,Fname,Dno from Employee,WorksOn,Project WHERE Essn=Ssn and Pno=Pnumber and Pno in (select Pno from WorksON,Employee WHERE Essn in (select Essn from WorksOn group by Essn having count(*)<=all(select count(*) from WorksON,Employee where DNum=DNo group by Essn )));
ERROR 1146 (42S02): Table 'COMPANY.WorksON' doesn't exist
mysql>  select distinct Ssn,Fname,Dno from Employee,WorksOn,Project WHERE Essn=Ssn and Pno=Pnumber and Pno in (select Pno from WorksON,Employee WHERE Essn in (select Essn from WorksOn group by Essn having count(*)<=all(select count(*) from WorksOn,Employee where DNum=DNo group by Essn )));
ERROR 1146 (42S02): Table 'COMPANY.WorksON' doesn't exist
mysql>  select distinct Ssn,Fname,Dno from Employee,WorksOn,Project WHERE Essn=Ssn and Pno=Pnumber and Pno in (select Pno from WorksOn,Employee WHERE Essn in (select Essn from WorksOn group by Essn having count(*)<=all(select count(*) from WorksOn,Employee where DNum=DNo group by Essn )));
+-----------+-----------+-----+
| Ssn       | Fname     | Dno |
+-----------+-----------+-----+
| 333445555 | VISHAL    |   5 |
| 888665555 | HARSHITHA |   1 |
| 234567891 | VINANTHI  |   5 |
| 453453453 | AISHU     |   5 |
| 666884444 | SANTHOSH  |   5 |
| 987654321 | RAMESH    |   4 |
| 123456789 | ARAVINDH  |   5 |
| 345678912 | PRIYA     |   4 |
| 987987987 | NAVYA     |   4 |
| 999887777 | VINITHA   |   4 |
+-----------+-----------+-----+
10 rows in set (0.01 sec)

mysql> select FName,LName from Employee,Project,WorksOn where Essn=Ssn and PNo=PNumber and PNo in(select PNo from WorksOn where Essn in (select Essn from (select Essn ,MIN(mycount),DNum from (select Essn,count(*)mycount,DNum from Project,WorksOn where PNumber=PNo group by DNum,Essn)mindept group by DNum,Essn)mindeptt));
+-----------+------------+
| FName     | LName      |
+-----------+------------+
| VISHAL    | MAHESWARAN |
| HARSHITHA | REDDY      |
| VINANTHI  | REDDY      |
| AISHU     | VENKY      |
| SANTHOSH  | VARUN      |
| RAMESH    | NARAYAN    |
| ARAVINDH  | PARANAN    |
| PRIYA     | DHARSHINI  |
| NAVYA     | RAKESH     |
| VINITHA   | MAHESH     |
+-----------+------------+
10 rows in set (0.05 sec)



