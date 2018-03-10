CREATE TABLE aeroporturi (
    cod_aeroport NUMBER(10),
    id_model NUMBER(10),
    nume_aeroport VARCHAR(100),
    tara_aeroport VARCHAR(100),
    cod_zbor NUMBER(10)
)

CREATE TABLE orase_deservite(
    cod_aeroport NUMBER(10),
    nume_oras VARCHAR(100)
)

CREATE TABLE model_avion(
    id_model VARCHAR(100),
    tip_avion VARCHAR(100),
    capacitate NUMBER(10),
    producator VARCHAR(100)

    CONSTRAINT id_model_pk PRIMARY KEY(id_model)
)

CREATE TABLE modele_acceptate(
    id_model NUMBER(10),
    cod_aeroport NUMBER(10)
)

CREATE TABLE zboruri(
    cod_zbor NUMBER(10),
    aeroport_plecare VARCHAR(100),
    aeroort_sosire VARCHAR(100),
    tarif NUMBER(10),
    data_plecare DATE,
    ora_plecare NUMBER(10),
)

CREATE TABLE rezervari(
    cod_rezervare NUMBER(10), 
    loc_rezervare NUMBER(10),
    serie_pasaport NUMBER(10),
    cod_zbor NUMBER(10),

    CONSTRAINT loc_unic_persoana UNIQUE(cod_zbor, loc_rezervare),
    CONSTRAINT persoana_mai_multe_locuri UNIQUE(cod_zbor, serie_pasaport),
    CONSTRAINT cod_rezervare_pk PRIMARY KEY(cod_rezervare)
)

CREATE TABLE persoane(
    serie_pasaport NUMBER(10),
    nume CHAR(100),
    prenume CHAR(100),
    numar_telefon NUMBER(10)
)