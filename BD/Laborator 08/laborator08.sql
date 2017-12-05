--CORREALTED SUBQUERY

--p1
select s1.nume, s1.prenume
from studenti s1 
where EXISTS 
      (select *
       from studenti s2 
       where s1.an = s2.an and 
       s1.data_nastere > s2.data_nastere);


--p2
select s1.nume, s1.prenume, round(avg(n1.valoare),2)
from studenti s1
join note n1 on s1.nr_matricol = n1.nr_matricol
group by s1.nume, s1.prenume, s1.nr_matricol, s1.an
having round(avg(n1.valoare),2) =
       (select max(round(avg(n2.valoare),2))
        from note n2
        join studenti s2 on s2.nr_matricol = n2.nr_matricol
        where s1.an = s2.an
        group by n2.nr_matricol, s2.an
       );


--p3
select s1.nume, s1.prenume, round(avg(n1.valoare),2)
from studenti s1 
join note n1 on s1.nr_matricol = n1.nr_matricol
group by s1.nume, s1.prenume, s1.nr_matricol, s1.an, s1.grupa
having round(avg(n1.valoare),2) = 
       (select max(round(avg(n2.valoare),2))
        from note n2 
        join studenti s2 on n2.nr_matricol = s2.nr_matricol
        where s1.grupa = s2.grupa and s1.an = s2.an
        group by n2.nr_matricol, s2.an, s2.grupa
       );


--p4
select s1.nume, s1.prenume, n1.valoare 
from studenti s1 
join note n1 on s1.nr_matricol = n1.nr_matricol 
join cursuri c1 on c1.id_curs = n1.id_curs 
where EXISTS 
      (select s2.nume, s2.prenume, n2.valoare
       from studenti s2
       join note n2 on s2.nr_matricol = n2.nr_matricol
       join cursuri c2 on c2.id_curs = n2.id_curs 
       where s1.an = s2.an and n1.valoare = n2.valoare and c1.titlu_curs = c2.titlu_curs and s1.nr_matricol <> s2.nr_matricol
      );
