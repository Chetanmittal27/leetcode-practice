with cte as (
    select id , temperature, recordDate,
    lag(recordDate , 1) over (order by recordDate) as prev_date,
    lag(temperature , 1) over (order by recordDate) as prev_temp from Weather
)

select id from cte
where temperature > prev_temp and datediff(recordDate , prev_date) = 1;