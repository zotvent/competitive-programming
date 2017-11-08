set @d = 0, @a = 0, @p = 0, @s = 0; 

select min(doctor), min(professor), min(singer), min(actor) from
    (select 
    	IF(occupation='actor', name, null) as actor, 
     	IF(occupation='doctor', name, null) as doctor, 
     	IF(occupation='professor', name, null) as professor, 
	    IF(occupation='singer', name, null) as singer, 
        case lower(occupation)
            when 'actor' then @a:=@a+1 
            when 'doctor' then @d:=@d+1 
            when 'professor' then @p:=@p+1 
            when 'singer' then @s:=@s+1 
        end as idn 
    from occupationS order by name) as tmp group by tmp.idn ;