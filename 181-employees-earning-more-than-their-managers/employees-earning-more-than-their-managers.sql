-- # Write your MySQL query statement below
-- SELECT name 
-- FROM Employee WHERE salary > (SELECT salary FROM Employee WHERE id=managerId);
-- don't use managerId = Null, Because NULL means unknown, SQL uses three-valued logic: True, False anmd Unknown

SELECT e1.name as Employee FROM Employee e1 WHERE e1.managerId IS NOT NULL
AND e1.salary > (
    SELECT e2.salary FROM Employee e2 WHERE e2.id = e1.managerId
    );  
