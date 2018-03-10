CREATE TABLE dealer(
    nume_vanzator VARCHAR(100),
    adresa_vanzator VARCHAR(100),
    id_oferta NUMBER(10),
    CONSTRAINT id_oferta_pk PRIMARY KEY(id_oferta)
)
/

CREATE TABLE oferte(
    id_oferta NUMBER(10),
    id_model number(10),
    nume_model VARCHAR(100),
    culoare VARCHAR(100),
    pret NUMBER(10),
    CONSTRAINT id_producator_pk PRIMARY KEY(id_producator)
)
/

CREATE TABLE producator(
    id_producator NUMBER(10),
    nume_producator VARCHAR(100)
)
/
CREATE TABLE model(
    nume_model VARCHAR(100),
    culoare_model VARCHAR(100),
    capacitate_cilindrica NUMBER(100)
)
/