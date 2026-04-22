# Write your MySQL query statement below
SELECT Person.lastName, Person.firstName, Address.city, Address.state 
FROM Person
LEFT OUTER JOIN Address on Person.personId = Address.personId;