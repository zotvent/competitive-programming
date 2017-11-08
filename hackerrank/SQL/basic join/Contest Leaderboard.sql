select h.hacker_id, h.name, sum(score) 
	from (
		select hacker_id, challenge_id, max(score) as score 
			from submissions 
		group by hacker_id, challenge_id) t
inner join hackers h on h.hacker_id = t.hacker_id
group by h.hacker_id, h.name
having sum(score) > 0
order by sum(score) desc, h.hacker_id asc;