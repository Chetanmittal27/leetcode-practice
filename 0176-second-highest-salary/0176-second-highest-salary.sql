select coalesce(
    (select distinct(salary) from Employee
    where salary < (select max(salary) from Employee)
    order by salary desc
    limit 1),
    
    null
) as SecondHighestSalary;
