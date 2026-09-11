with cte as (
    select person_id , person_name,
    sum(weight) over (ROWS BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW) as curr_weight
    from Queue order by turn
)


select person_name from cte 
where curr_weight <= 1000 
order by curr_weight desc
limit 1;