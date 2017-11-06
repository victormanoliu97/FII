--p2 
select s.nume, s.prenume, p.nume, p.prenume
from studenti s 
join note n on s.nr_matricol = n.nr_matricol
join cursuri c on n.id_curs = c.id_curs 
join didactic d on c.id_curs = d.id_curs 
join profesori p on p.id_prof = d.id_prof 
where length(s.nume) = length(p.nume);

--p3 
select DISTINCT c.titlu_curs
from cursuri c 
join note n on c.id_curs = n.id_curs 
where n.valoare<=8;

--p4 
select DISTINCT s.nume, s.prenume 
from studenti s 
join note n on s.nr_matricol = n.nr_matricol
where n.valoare>7 or n.valoare=7;

--p5 
select s.nume, s.prenume 
from studenti s 
join note n on s.nr_matricol = n.nr_matricol 
join cursuri c on c.id_curs = n.id_curs 
where trim(c.id_curs) like '23' and (n.valoare=7 or n.valoare=10) and trim(to_char(n.data_notare, 'Day')) like 'Tuesday';

--p6 
select s.nume, s.prenume, n.valoare, to_char(n.data_notare, 'Month')||','||extract(year from n.data_notare), decode( cast(to_char(last_day(data_notare),'dd') AS INT), 30, null, '+')
from studenti s 
join note n on s.nr_matricol = n.nr_matricol 
join cursuri c on c.id_curs = n.id_curs 
where n.valoare>=5;