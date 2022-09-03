# Write your MySQL query statement below
select a.name as 'Employee' from Employee As a,Employee as b where a.ManagerId=b.id and a.salary>b.salary;
