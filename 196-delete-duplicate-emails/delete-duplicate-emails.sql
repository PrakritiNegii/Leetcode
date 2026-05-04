# Write your MySQL query statement below
DELETE FROM Person
WHERE id NOT IN (       #runs per row (just a simple check, not a re-running query)
    SELECT id FROM (    #runs only once
        SELECT min(id) AS id
            FROM Person
            GROUP BY email) 
        temp
);