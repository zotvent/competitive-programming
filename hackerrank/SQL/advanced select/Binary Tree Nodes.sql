select n, 
	if(p is null, 'Root', 
		if((select count(*) from bst where p=b.n)>0, 'Inner', 'Leaf')
	) from bst as b order by n;