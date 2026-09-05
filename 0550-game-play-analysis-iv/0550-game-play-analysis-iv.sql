with first_login as (
    select player_id , min(event_date) as firstDate from activity
    group by player_id
),

cte as (
    select f.player_id from first_login f
    join
    activity a on f.player_id = a.player_id
    where datediff(a.event_date , f.firstDate) = 1
)

select round(count(distinct(cte.player_id)) * 1.0 / (select count(distinct(player_id))  from activity) , 2) as fraction
from cte;