with cte as (
    select reports_to , count(employee_id) as reports_count , round(avg(age)) as average_age from Employees
    where reports_to IS NOT NULL
    group by reports_to
)

select e.employee_id , e.name , c.reports_count , c.average_age from Employees e
join
cte c on e.employee_id = c.reports_to
order by e.employee_id asc;