SELECT t.dept_name AS Department,
       t.name AS Employee,
       t.salary AS Salary
FROM (
    SELECT 
        d.name AS dept_name,
        e.name,
        e.salary,
        RANK() OVER (
            PARTITION BY e.departmentId
            ORDER BY e.salary DESC
        ) AS rnk
    FROM Employee e
    JOIN Department d
        ON e.departmentId = d.id
) AS t
WHERE t.rnk = 1;