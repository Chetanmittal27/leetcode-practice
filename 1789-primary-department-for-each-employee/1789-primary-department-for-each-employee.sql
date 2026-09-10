with cte as (
    select employee_id, department_id, primary_flag,
    row_number() over(partition by employee_id order by case
                                                    when primary_flag = 'Y' then 1
                                                    when primary_flag = 'N' then 2
                                                    end
    ) as rn from Employee
)


select employee_id , department_id from cte 
where rn = 1;