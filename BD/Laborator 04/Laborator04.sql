--p1
select s.nume, s.prenume, n.valoare, p.nume, p.prenume
from studenti s
join note n on s.nr_matricol = n.nr_matricol
join didactic d on n.id_curs = d.id_curs
join profesori p on p.id_prof = d.id_prof;

--p2
select s.nume, s.prenume, n.valoare
from studenti s 
join note n on s.nr_matricol = n.nr_matricol
join cursuri c on c.id_curs = n.id_curs
where n.valoare=10 and c.id_curs like '24';

--p3
select p.nume, p.prenume, c.titlu_curs
from profesori p 
join didactic d on d.id_prof = p.id_prof
join cursuri c on d.id_curs = c.id_curs;

--p5
select p.nume, p.prenume, c.titlu_curs
from profesori p 
right join didactic d on d.id_prof = p.id_prof 
right join cursuri c on c.id_curs = d.id_curs 
where p.nume is null;

--p7
select s1.nume||'-'||s2.nume, to_char(s1.data_nastere, 'day')
from studenti s1 
join studenti s2 on to_char(s1.data_nastere, 'day') = to_char(s2.data_nastere, 'day')
where s1.nr_matricol > s2.nr_matricol;

--p8
