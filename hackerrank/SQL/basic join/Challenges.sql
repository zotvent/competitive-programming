select c.hacker_id, h.name, count(c.hacker_id) as c_count
    from hackers h inner join challenges c on h.hacker_id = c.hacker_id
group by c.hacker_id, h.name
having
    c_count = (select max(t1.cnt1) 
        from (select count(hacker_id) as cnt1 from challenges group by hacker_id) t1) 
    or c_count in (
        select t2.cnt2
            from (select count(*) as cnt2 from challenges group by hacker_id) t2
        group by t2.cnt2
        having count(t2.cnt2) = 1
    )
order by c_count desc, c.hacker_id asc;