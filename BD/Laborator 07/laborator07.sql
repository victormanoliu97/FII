
/* Uncorrelated Subquery */

--p1 
select nume from (select nume, max(bursa)
                  from studenti 
                  group by nume, nr_matricol
                  order by max(bursa) desc)
where rownum=1;


--p2
select nume from studenti where an in 
                               (select an from studenti where nume like 'Arhire')
                          and grupa in 
                               (select grupa from studenti where nume like 'Arhire')
                          and nume not like 'Arhire'; 


--p3 
select nume, prenume, grupa, valoare 
from studenti s 
join note n on s.nr_matricol = n.nr_matricol 
where (s.grupa, n.valoare) in (
    select grupa, min(valoare)
    from studenti s 
    join note n on s.nr_matricol = n.nr_matricol
    group by s.grupa);


--p4 
select nume, "MEDIESTUD" from (select nr_matricol, avg(valoare) as "MEDIESTUD"
                  from note 
                  group by nr_matricol) m,
                  (select avg(valoare) as "MEDIEGLOBALA"
                  from note) g, 
                  studenti s 
                  where "MEDIEGLOBALA"<"MEDIESTUD" and s.nr_matricol = m.nr_matricol;


select s.nume, avg(n.valoare)
from studenti s 
join note n on s.nr_matricol = n.nr_matricol
group by s.nume, s.nr_matricol
having avg(n.valoare) > (select avg(n.valoare) from note n);


--p5 
select nume from (    select s.nume, avg(n.valoare)
                      from studenti s 
                      join note n on s.nr_matricol = n.nr_matricol
                      group by s.nume, s.nr_matricol 
                      order by avg(n.valoare) desc )
where rownum<=3;


--p6 
select s.nume, avg(n.valoare)
from studenti s 
join note n on s.nr_matricol = n.nr_matricol
group by s.nume, s.nr_matricol
having avg(n.valoare) = ( select max(avg(n.valoare)) 
                          from studenti s 
                          join note n on s.nr_matricol = n.nr_matricol
                          group by n.nr_matricol );


--p7
select s.nume, s.prenume from studenti s 
join note n on s.nr_matricol = n.nr_matricol 
join cursuri c on c.id_curs = n.id_curs 
where c.titlu_curs = 'Logica' and 
n.valoare in (select n.valoare from note n 
              join cursuri c on n.id_curs = c.id_curs
              join studenti s on s.nr_matricol = n.nr_matricol
              where s.nume like 'Ciobotariu'
              and c.titlu_curs like 'Logica')
and s.nume like 'Ciobotariu' and s.prenume like 'Ciprian';
                  
