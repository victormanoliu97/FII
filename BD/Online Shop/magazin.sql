drop table categorii_produs
/
drop table produse
/
drop table clienti
/
drop table specificatii
/
drop table adrese
/
drop table comenzi
/

create table categorii_produs(
id_categorie NUMBER(3),
nume_categorie VARCHAR2(10),
CONSTRAINT categorii_pk PRIMARY KEY (id_categorie)
)
/

create table produse(
id_produs NUMBER(3),
id_categorie NUMBER(3),
nume_produs VARCHAR2(10),
producator VARCHAR2(10),
pret NUMBER(4),
descriere_produs VARCHAR2(100),
constraint PK2 primary key (id_produs),
CONSTRAINT fk_id_categorie
    FOREIGN KEY (id_categorie)
    REFERENCES categorii_produs (id_categorie)
)
/

create table clienti(
id_client number(3),
nume_client VARCHAR2(10),
prenume_client VARCHAR2(10),
telefon_client NUMBER(10),
CONSTRAINT clienti_pk PRIMARY KEY (id_client)
)
/

create table specificatii(
id_specificatie NUMBER(3),
id_produs NUMBER(3),
diagonala number(3),
procesor varchar2(100),
RAM number(2),
material varchar(10),
constraint produs_pk primary key (id_produs)
)
/

create table adrese_clienti(
id_adresa NUMBER(3),
oras varchar2(10),
judet varchar2(10),
strada varchar2(20),
id_client number(3),
constraint adresa_pk primary key (id_adresa),
CONSTRAINT fk_id_client
    FOREIGN KEY (id_client)
    REFERENCES clienti (id_client)
)
/

create table comenzi(
id_comanda NUMBER(3),
data_comanda DATE,
status_comanda varchar(10),
id_produs number(3),
id_client number(3),
CONSTRAINT comenzi_pk PRIMARY KEY (id_comanda),
CONSTRAINT fk_id_produs2
    FOREIGN KEY (id_produs)
    REFERENCES produse (id_produs),
constraint fk_id_client2 
foreign key (id_client)
references clienti (id_client)
)
/

INSERT INTO categorii_produs VALUES(111, 'electronice');
INSERT INTO categorii_produs VALUES(112, 'laptopuri');

INSERT INTO produse VALUES(111, 111, 'ASUS ZENROGUE', 'ASUS', 3200, 'Alegerea pentru gamming');
INSERT INTO produse VALUES(112, 112, 'Laptop Levono B51-80', 'Lenovo', 2500, 'Alegerea pentru business');

INSERT INTO clienti VALUES(111, 'Ionescu', 'Andrei', 752094300);
INSERT INTO clienti VALUES(112, 'Popescu', 'Ion', 763185411);

INSERT INTO specificatii VALUES(411, 111, 17, 'i7-6700', 16, 'metal');
INSERT INTO specificatii VALUES(412, 112, 15, 'i7-6500U', 8, 'plastic');

INSERT INTO adrese_clienti VALUES(311, 'Iasi', 'Iasi', 'Tudor', 111);
INSERT INTO adrese_clienti VALUES(322, 'Bacau', 'Bacau', 'Cancivo', 112);

INSERT INTO comenzi VALUES(611, TO_DATE('15/07/2017', 'dd/mm/yyyy'), 'Asteptare', 111, 111);
INSERT INTO comenzi VALUES(622, TO_DATE('16/07/2017', 'dd/mm/yyyy'), 'Livrat', 112, 112);
