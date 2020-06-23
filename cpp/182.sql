# Write your MySQL query statement below
select Email from (select Email, count(*) as c from Person group by Email) where c > 1