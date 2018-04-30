create table artists(
    id integer not null,
    name varchar(100) not null,
    country varchar(100),
    primary key (id)
);

create SEQUENCE artists_sequence START WITH 1 INCREMENT BY 1;

create or REPLACE trigger artists_trigger
  BEFORE INSERT on artists REFERENCING new as new
  for EACH ROW
  begin
    select artists_sequence.nextval into :new.id from dual;
  END;


create table albums(
    id integer not null,
    name varchar(100) not null,
    artist_id integer not null references artists ON DELETE SET NULL,
    release_year integer,
    primary key (id)
);

create SEQUENCE albums_sequence START WITH 1 INCREMENT BY 1;

create or REPLACE trigger albums_trigger
  BEFORE INSERT on albums REFERENCING new as new
  for EACH ROW
  begin
    select albums_sequence.nextval into :new.id from dual;
  END;


create table charts(
  id integer not null,
  artist_id integer not null REFERENCES artists on DELETE SET NULL,
  album_id integer not null references albums on DELETE SET NULL,
  placement integer not null,
  primary key (id)
);

create SEQUENCE charts_sequence START WITH 1 INCREMENT BY 1;

CREATE OR REPLACE TRIGGER charts_trigger
  BEFORE INSERT ON charts REFERENCING new as new
  for EACH ROW
  begin
    select charts_sequence.nextval into :new.id FROM dual;
  END;