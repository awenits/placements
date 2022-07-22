### Q1. Max salary from Employee table
SELECT max(salary) FROM Employee;

### Q2. Second Highest salary from Employee table

SELECT
    IFNULL(
      (SELECT DISTINCT Salary
       FROM Employee
       ORDER BY Salary DESC
       LIMIT 1 OFFSET 1),
    NULL) AS SecondHighestSalary;
    

SELECT
    (SELECT DISTINCT
            Salary
        FROM
            Employee
        ORDER BY Salary DESC
        LIMIT 1 OFFSET 1) AS SecondHighestSalary;
        
### Q3. Third Highest salary from Employee table

SELECT
    IFNULL(
      (SELECT DISTINCT Salary
       FROM Employee
       ORDER BY Salary DESC
        LIMIT 1 OFFSET 2),
    NULL) AS SecondHighestSalary;
