--p1 
SELECT an, count(*)
FROM studenti
GROUP BY an;

--p2 
select an, grupa, count(*)
from studenti
group by an,grupa
order by an asc, grupa asc;

--p3 
select an, grupa, count(*), count(bursa)
from studenti 
group by an,grupa;

--p4 
select sum(bursa) from studenti where bursa is not null;

--p5 
select avg(nvl(bursa,0)) from studenti;

--p6 
select valoare, count(*)
from note 
group by valoare
order by valoare desc;

--p7 
select valoare, to_char(data_notare, 'Day'), count(*)
from note 
group by valoare, to_char(data_notare, 'Day')
order by count(*) desc;

--p8
select valoare, to_char(data_notare, 'Day'), count(*)
from note 
group by valoare, to_char(data_notare, 'Day')
order by to_char(data_notare, 'Day') asc;

--p9 
select s.nume, avg(n.valoare)
from studenti s 
join note n on s.nr_matricol = n.nr_matricol
group by s.nume, s.nr_matricol
having count(n.valoare)>0
order by avg(n.valoare) desc; 

--p10 
select s.nume, avg(n.valoare)
from studenti s 
left join note n on s.nr_matricol = n.nr_matricol
group by s.nume, s.nr_matricol
order by avg(n.valoare) desc;

--p11
select s.nume, avg(nvl(n.valoare,0))
from studenti s 
left join note n on s.nr_matricol = n.nr_matricol
group by s.nume, s.nr_matricol
order by avg(n.valoare) desc;

--p12 
select s.nume, avg(n.valoare)
from studenti s 
join note n on s.nr_matricol = n.nr_matricol
group by s.nume, s.nr_matricol
having avg(valoare)>8;

--p13 
select s.nume, max(n.valoare), min(n.valoare), avg(n.valoare)
from studenti s 
join note n on s.nr_matricol = n.nr_matricol
group by s.nume, s.nr_matricol
having min(n.valoare)>=7;

--p14 
select s.nume, max(n.valoare), min(n.valoare), avg(n.valoare)
from studenti s 
join note n on s.nr_matricol = n.nr_matricol
group by s.nume, s.nr_matricol
having count(valoare)>4;

--p15 
select s.nume, max(n.valoare), min(n.valoare), avg(n.valoare)
from studenti s 
join note n on s.nr_matricol = n.nr_matricol
where grupa like 'A2' and an=3
group by s.nume, s.nr_matricol;

--p16 
select max(avg(valoare))
from note 
group by nr_matricol;

--p17
select c.titlu_curs, min(n.valoare), max(n.valoare)
from cursuri c 
join note n on c.id_curs = n.id_curs
group by c.titlu_curs, c.id_curs;