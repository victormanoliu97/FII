--p1
SELECT nume, prenume, an, data_nastere FROM studenti;

--p2
SELECT DISTINCT bursa FROM studenti;

--p4
SELECT ' '||nume||' '||prenume||','|| an ||'' AS "Studenti pe ani de studiu" FROM studenti ORDER BY an ASC;

--p5
SELECT nume, prenume, data_nastere FROM studenti WHERE data_nastere >= TO_DATE('1/01/1995', 'dd/mm/yyyy') AND data_nastere <= TO_DATE('10/06/1997', 'dd/mm/yyyy') ORDER BY an DESC;

--p6
SELECT nume, prenume, an FROM studenti WHERE data_nastere >= TO_DATE('1/01/1995', 'dd/mm/yyyy') AND data_nastere <= TO_DATE('31/12/1995', 'dd/mm/yyyy');

--p7
SELECT nume, prenume, an, grupa, data_nastere FROM studenti WHERE bursa IS NULL;

--p8
SELECT nume, prenume FROM studenti WHERE bursa IS NOT NULL AND an = 2 OR an = 3 ORDER BY nume ASC , prenume DESC;

--p9
SELECT nume, prenume, an, grupa, bursa+(15/100)*bursa , data_nastere FROM studenti WHERE bursa IS NOT NULL;

--p10
SELECT nume, prenume, an, grupa, data_nastere FROM studenti WHERE nume LIKE 'P%' AND an=1;

--p11
SELECT nume, prenume, an, grupa, data_nastere FROM studenti WHERE LENGTH(prenume) - LENGTH(REPLACE(prenume, 'a', '')) = 2;

--p12
SELECT nume, prenume, an, grupa, data_nastere FROM studenti WHERE prenume='Ioana' OR prenume='Marius' OR prenume='Alexandru';

--p13
SELECT nume, prenume, an, grupa, bursa, data_nastere FROM studenti WHERE grupa LIKE 'A%' AND bursa IS NOT NULL;

--p14
SELECT nume, prenume FROM profesori WHERE prenume LIKE '%_n';