--p1
SELECT CURRENT_DATE FROM DUAL;

--p2
SELECT nume, prenume, data_nastere , CEIL(MONTHS_BETWEEN(TO_DATE(data_nastere, 'DD-MM-YYYY'), TO_DATE(CURRENT_DATE, 'DD-MM-YYYY'))) FROM studenti;

--P3
SELECT TO_CHAR(TO_DATE(data_nastere, 'DD-MM-YYYY'), 'DAY') FROM studenti;      --get the day when a student was born

--p4
SELECT CONCAT(CONCAT('Elevul ' , prenume), CONCAT(' este in grupa ', grupa)) FROM studenti;

--p5


--p6
SELECT CONCAT(LOWER(SUBSTR(nume, 1,1)), UPPER(SUBSTR(nume,2,LENGTH(nume))))  FROM profesori WHERE nume LIKE 'B%';

--p7
SELECT nume, prenume, data_nastere, TO_CHAR(TO_DATE(data_nastere, 'DD-MM-YYY'), 'DAY'), TO_CHAR(TO_DATE(data_nastere, 'DD-MM-YYY'), 'MONTH'), TO_CHAR(TO_DATE(data_nastere, 'DD-MM-YYY'), 'YEAR')  FROM studenti;

--p8
SELECT nume, prenume, TO_CHAR(TO_DATE(data_nastere, 'DD-MM-YYY'),'MONTH') FROM studenti WHERE bursa is NULL ORDER BY TO_CHAR(TO_DATE(data_nastere, 'DD-MM-YYY'),'MONTH') ASC;

--p9
SELECT nume, prenume, 'premiu 1' , nume, prenume , 'premiu 2', nume, prenume, 'premiu 3'
FROM studenti
WHERE bursa=450 OR bursa=350 OR bursa=250;

--P10
SELECT TRANSLATE(nume, 'i', 'a'), TRANSLATE(nume, 'a', 'i') FROM studenti;

--p11
SELECT nume, TRUNC(MONTHS_BETWEEN(CURRENT_DATE, data_nastere)/12), 
TRUNC(MONTHS_BETWEEN(CURRENT_DATE,data_nastere) - (TRUNC(MONTHS_BETWEEN(CURRENT_DATE,data_nastere)/12)*12)) , 
TRUNC(CURRENT_DATE) - ADD_MONTHS(data_nastere, TRUNC(MONTHS_BETWEEN(CURRENT_DATE,data_nastere))) 
FROM studenti;

--P12
SELECT nume, prenume, 450*0.15+NVL(bursa,0), 0.10*350+NVL(bursa,0) , 0.20*250+NVL(bursa,0), LAST_DAY(CURRENT_DATE)+1 FROM studenti;

--P13
SELECT nume, bursa FROM studenti WHERE bursa IS NOT NULL;