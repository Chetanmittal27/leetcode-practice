with cte as (
    select id, departmentId, name, salary,
    dense_rank() over(partition by departmentId order by salary desc) as rnk
    from Employee
)

select d.name as Department, c.name as Employee, c.salary as Salary from Department d
join
cte c on d.id = c.departmentId
where c.rnk < 4
order by c.salary desc;