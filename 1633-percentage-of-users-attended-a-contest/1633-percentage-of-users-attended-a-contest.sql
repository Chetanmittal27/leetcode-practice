with cte as (
    select r.contest_id , round(count(u.user_id) * 100.0 / (select count(*) from users) , 2) as percentage from Register r
    left join
    Users u on r.user_id = u.user_id
    group by r.contest_id
)

select contest_id , percentage from cte
order by percentage desc , contest_id asc;