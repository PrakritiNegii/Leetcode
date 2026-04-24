-- # Write your MySQL query statement below
-- SELECT name 
-- FROM Employee WHERE salary > (SELECT salary FROM Employee WHERE id=managerId);
-- don't use managerId = Null, Because NULL means unknown, SQL uses three-valued logic: True, False anmd Unknown

    SELECT e1.name as Employee FROM Employee e1
    LEFT JOIN Employee e2 
    ON e1.managerId = e2.id 
    WHERE e1.salary > e2.salary;
