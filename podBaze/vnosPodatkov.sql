SET FOREIGN_KEY_CHECKS=0;
DROP TABLE IF EXISTS Klet_has_Proizvajalec;
DROP TABLE IF EXISTS Prodaja;
DROP TABLE IF EXISTS Rajon;
DROP TABLE IF EXISTS Stranka;
DROP TABLE IF EXISTS Degustacija;
DROP TABLE IF EXISTS Klet_has_Vino;
DROP TABLE IF EXISTS Prodaja_has_Vino;
DROP TABLE IF EXISTS Serija;
DROP TABLE IF EXISTS Vino;
DROP TABLE IF EXISTS Degustacija_has_Vino;
DROP TABLE IF EXISTS Nakup;
DROP TABLE IF EXISTS Proizvajalec;
DROP TABLE IF EXISTS Sorta;
DROP TABLE IF EXISTS Vino_has_Sorta;
DROP TABLE IF EXISTS Klet;
DROP TABLE IF EXISTS Nakup_has_Vino;
DROP TABLE IF EXISTS Proizvajalec_has_Vino;
DROP TABLE IF EXISTS Sorta_has_Rajon;
SET FOREIGN_KEY_CHECKS=1;

create table Proizvajalec(
idProizvajalec int primary key auto_increment not null,
naziv text not null,
naslov text not null,
davcna int not null
);

create table Degustacija(
idDegustacija int primary key auto_increment not null,
naziv text not null,
datum date not null
);

create table Rajon(
idRajon int primary key auto_increment not null,
naziv text not null
);

create table Klet(
idKlet int primary key auto_increment not null,
naziv text not null,
tel_stevilka text not null,
naslov text not null
);

create table Serija(
idSerija int primary key auto_increment not null,
idProizvajalec int not null,
stevilka int not null,
datum date not null,
foreign key (idProizvajalec) references Proizvajalec(idProizvajalec)
);

create table Sorta(
idSorta int primary key auto_increment not null,
naziv text
);

create table Nakup(
idNakup int primary key auto_increment not null,
idKlet int not null,
idProizvajalec int not null,
datum date not null,
foreign key(idKlet) references Klet(idKlet),
foreign key(idProizvajalec) references Proizvajalec(idProizvajalec)
);

create table Stranka(
idStranka int primary key auto_increment not null,
naziv text not null,
naslov text not null
);

create table Vino(
idVino int primary key auto_increment not null,
idSerija int not null,
naziv text not null,
letnik int not null,
alkohol double not null,
cenaLiter decimal not null,
foreign key(idSerija) references Serija(idSerija)
);

create table Prodaja(
idProdaja int primary key auto_increment not null,
idKlet int not null,
idStranka int not null,
datum date not null,
znesek double,
foreign key (idKlet) references Klet(idKlet),
foreign key (idStranka) references Stranka(idStranka)
);

create table Klet_has_Vino(
idKolicinaKletVino int primary key auto_increment not null,
idKlet int not null,
idVino int not null,
kolicina double,
foreign key(idKlet) references Klet(idKlet),
foreign key(idVino) references Vino(idVino)
);

create table Sorta_has_Rajon(
idSortaRajon int primary key auto_increment not null,
idSorta int not null,
idRajon int not null,
foreign key(idSorta) references Sorta(idSorta),
foreign key(idRajon) references Rajon(idRajon)
);

create table Vino_has_Sorta(
idVinoSorta int primary key auto_increment not null,
idVino int not null,
idSorta int not null,
procent decimal,
foreign key (idVino) references Vino(idVino),
foreign key (idSorta) references Sorta(idSorta)
);

create table Nakup_has_Vino(
idNakupVino int primary key auto_increment not null,
idNakup int not null,
idVino int not null,
kolicina int not null,
foreign key(idNakup) references Nakup(idNakup),
foreign key(idVino) references Vino(idVino)
);

create table Klet_has_Proizvajalec(
idKletProizvajalec int primary key auto_increment not null,
idKlet int not null,
idProizvajalec int not null,
datum date not null,
foreign key(idKlet) references Klet(idKlet),
foreign key(idProizvajalec) references Proizvajalec(idProizvajalec)
);

create table Prodaja_has_Vino(
idProdajaVino int primary key auto_increment not null,
idProdaja int not null,
idVino int not null,
kolicina int not null,
cena double,
foreign key (idVino) references Vino(idVino),
foreign key (idProdaja) references Prodaja(idProdaja)
);

create table Degustacija_has_Vino(
idDegustacijaVino int primary key auto_increment not null,
idDegustacija int not null,
idVino int not null,
cena double not null,
foreign key(idDegustacija) references Degustacija(idDegustacija),
foreign key(idVino) references Vino(idVino)
);

create table Proizvajalec_has_Vino(
idProizvajalecVino int primary key auto_increment not null,
idProizvajalec int not null,
idVino int not null,
datum date not null,
foreign key (idProizvajalec) references Proizvajalec(idProizvajalec),
foreign key (idVino) references Vino(idVino)
);

insert into Proizvajalec (naziv, naslov, davcna)
values ("Proizvajalec1", "Naslov1", 100000),
("Proizvajalec2", "Naslov2", 100010),
("Proizvajalec3", "Naslov3", 1203004),
("Proizvajalec4", "Naslov4", 122324),
("Proizvajalec5", "Naslov5", 443434);

insert into Degustacija (naziv, datum)
values ("10. obletnica Braundo-ja", DATE(19991107)),
("Degustacija2", DATE(20171201)),
("Degustacija15", DATE(18700122)),
("DegustacijaDFD", DATE(21110201)),
("Degustacija4434", DATE(40270507));

insert into Rajon(naziv)
values ("Rajon1"),
("Rajon2"),
("Rajon3"),
("Rajon4"),
("Rajon5");

insert into Klet(naziv, tel_stevilka, naslov) values
("Klet1", "090", "naslov1"),
("Klet2", "080", "naslov2"),
("Klet3", "070", "naslov3"),
("Klet4", "060", "naslov4"),
("Klet5", "050", "naslov5");

insert into Serija(idProizvajalec, stevilka, datum) values
(1, 100, DATE(20110708)),
(2, 200, DATE(20110708)),
(3, 300, DATE(20110708)),
(4, 400, DATE(20110708)),
(5, 500, DATE(20110708)),
(1, 510, DATE(20110708)),
(2, 520, DATE(20110708)),
(3, 530, DATE(20110708)),
(4, 540, DATE(20110708)),
(5, 550, DATE(20110708));

insert into Sorta(naziv) values
("Sorta1"),
("Sorta2"),
("Rebula"),
("Sorta4"),
("Sorta5");

insert into Nakup(idKlet, idProizvajalec,  datum) values
(1, 1, DATE(20110101)),
(2, 5, DATE(20110101)),
(2, 4, DATE(20110101)),
(3, 3, DATE(20110101)),
(5, 2, DATE(20110101)),
(3, 2, DATE(20110101)),
(4, 2, DATE(20110101)),
(2, 2, DATE(20110101)),
(1, 4, DATE(20110101)),
(5, 3, DATE(20110101));


insert into Stranka(naziv, naslov) values
("Stranka1", "naslov1"),
("Stranka2", "naslov1"),
("Stranka3", "naslov1"),
("Stranka4", "naslov1"),
("Stranka5", "naslov1");

insert into Vino(idSerija, naziv, letnik, alkohol, cenaLiter) values
(2, "Braundo", 2008, 0.5, 15),
(1, "laski rizling", 1996, 0.5, 10),
(3, "Braundo", 2011, 0.5, 8),
(4, "naziv5", 2013, 0.5, 12),
(5, "naziv5", 2015, 0.5, 10),
(1, "naziv5", 2013, 0.5, 7.2),
(2, "naziv5", 2005, 0.5, 9.8),
(3, "naziv16", 2107, 0.5, 10),
(4, "naziv16", 2222, 0.5, 20),
(5, "naziv16", 3005, 0.5, 12);

insert into Prodaja(idKlet, idStranka, datum, znesek) values 
(1, 2, DATE(20010212), 0),
(2, 3, DATE(20010212), 0),
(3, 3, DATE(20010212), 0),
(4, 1, DATE(20010212), 0),
(5, 2, DATE(20010212), 0),
(1, 3, DATE(20010212), 0),
(2, 3, DATE(20010212), 0),
(3, 2, DATE(20010212), 0),
(4, 3, DATE(20010212), 0),
(5, 3, DATE(20010212), 0);

insert into Klet_has_Vino(idKlet, idVino, kolicina) values
(1, 2, 10),
(2, 2, 80),
(3, 2, 100),
(4, 2, 50),
(5, 2, 82),
(1, 3, 101),
(2, 3, 50),
(3, 3, 78),
(4, 3, 88),
(5, 3, 98);

insert into Sorta_has_Rajon(idSorta, idRajon) values
(1, 2),
(2, 2),
(3, 2),
(4, 2),
(5, 2),
(1, 3),
(2, 3),
(3, 3),
(4, 3),
(5, 3);

insert into Vino_has_Sorta(idVino, idSorta, procent) values
(1, 2, 0.1),
(2, 2, 0.1),
(3, 2, 0.1),
(4, 2, 0.1),
(5, 2, 0.1),
(1, 3, 0.1),
(2, 3, 0.1),
(3, 3, 0.1),
(4, 3, 0.1),
(5, 3, 0.1);

insert into Nakup_has_Vino(idNakup, idVino, kolicina) values
(1, 2, 1),
(2, 2, 1),
(3, 2, 1),
(4, 2, 1),
(5, 2, 1),
(1, 3, 1),
(2, 3, 1),
(3, 3, 1),
(4, 3, 1),
(5, 3, 1);

insert into Klet_has_Proizvajalec(idKlet, idProizvajalec, datum) values
(1, 2, DATE(20110101)),
(2, 2, DATE(20110101)),
(3, 2, DATE(20110101)),
(4, 2, DATE(20110101)),
(5, 2, DATE(20110101)),
(1, 3, DATE(20110101)),
(2, 3, DATE(20110101)),
(3, 3, DATE(20110101)),
(4, 3, DATE(20110101)),
(5, 3, DATE(20110101));

insert into Prodaja_has_Vino(idProdaja, idVino, kolicina) values 
(1, 2, 1),
(1, 2, 2),
(1, 2, 3),
(2, 2, 4),
(2, 2, 4),
(4, 3, 5),
(4, 3, 6),
(3, 3, 7),
(3, 3, 12),
(10, 3, 9);

SET SQL_SAFE_UPDATES = 0;
#dodajamo skupne cene za vsako vino v prodaji
update Prodaja_has_Vino
set cena = (select Prodaja_has_Vino.kolicina * (select cenaLiter from Vino where Prodaja_has_Vino.idVino = Vino.idVino))
where Prodaja_has_Vino.idVino in (select idVino from Vino);

#dodajamo skupne zneske prodaj

update Prodaja
set Prodaja.znesek = (select Prodaja.znesek + (select sum(cena) from Prodaja_has_Vino where Prodaja.idProdaja = Prodaja_has_Vino.idProdaja))
where Prodaja.idProdaja in (select Prodaja_has_Vino.idProdaja from Prodaja_has_Vino);

insert into Degustacija_has_Vino(idDegustacija, idVino, cena) values
(1, 2, 1),
(2, 2, 1),
(3, 2, 1),
(4, 2, 1),
(5, 2, 1),
(1, 3, 1),
(2, 3, 1),
(3, 3, 1),
(4, 3, 1),
(5, 3, 1);

insert into Proizvajalec_has_Vino(idProizvajalec, idVino, datum) values
(1, 2, DATE(20110101)),
(2, 2, DATE(20110101)),
(3, 2, DATE(20110101)),
(4, 2, DATE(20110101)),
(5, 2, DATE(20110101)),
(1, 3, DATE(20110101)),
(2, 3, DATE(20110101)),
(3, 3, DATE(20110101)),
(4, 3, DATE(20110101)),
(5, 3, DATE(20110101));