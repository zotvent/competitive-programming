--WHERE CLAUSE
select hacker_id, name
from (
	select count(*) as total, h.hacker_id, h.name 
	from hackers h, Difficulty d, Challenges c, Submissions s 
	where h.hacker_id = s.hacker_id and 
		s.challenge_id = c.challenge_id and 
		c.difficulty_level = d.difficulty_level and 
		s.score=d.score
	group by h.hacker_id, h.name
	order by h.hacker_id) as t
where t.total > 1
order by t.total desc, hacker_id asc;


--INNER JOIN
select h.hacker_id, h.name
from submissions s
inner join challenges c
on s.challenge_id = c.challenge_id
inner join difficulty d
on c.difficulty_level = d.difficulty_level
inner join hackers h
on s.hacker_id = h.hacker_id
where s.score = d.score
group by h.hacker_id, h.name
having count(h.hacker_id)>1
order by count(h.hacker_id) desc, h.hacker_id asc;