SET FOREIGN_KEY_CHECKS=0;
DROP TABLE Klet_has_Proizvajalec;
DROP TABLE Prodaja;
DROP TABLE Rajon;
DROP TABLE Stranka;
DROP TABLE Degustacija;
DROP TABLE Klet_has_Vino;
DROP TABLE Prodaja_has_Vino;
DROP TABLE Serija;
DROP TABLE Vino;
DROP TABLE Degustacija_has_Vino;
DROP TABLE Nakup;
DROP TABLE Proizvajalec;
DROP TABLE Sorta;
DROP TABLE Vino_has_Sorta;
DROP TABLE Klet;
DROP TABLE Nakup_has_Vino;
DROP TABLE Proizvajalec_has_Vino;
DROP TABLE Sorta_has_Rajon;
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

create table Proizvajalec_has_Vino(
idProizvajalecVino int primary key auto_increment not null,
datum date not null
);

create table Degustacija_has_Vino(
cena double not null
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
stevilka int not null,
datum date not null
);

create table Klet_has_Proizvajalec(
idKletProizvajalec int primary key auto_increment not null,
datum date not null
);

create table Sorta(
idSorta int primary key auto_increment not null,
naziv text
);

create table Klet_has_Vino(
idKolicinaKletVino int primary key auto_increment not null
);

create table Sorta_has_Rajon(
idSortaRajon int primary key auto_increment not null
);

create table Nakup(
idNakup int primary key auto_increment not null,
datum date not null
);

create table Stranka(
idStranka int primary key auto_increment not null,
naziv text not null,
naslov text not null
);

create table Nakup_has_Vino(
idNakupVino int primary key auto_increment not null,
kolicina int not null
);

create table Vino(
idVino int primary key auto_increment not null,
naziv text not null,
letnik int not null,
alkohol decimal not null
);

create table Prodaja(
idProdaja int primary key auto_increment not null,
datum date not null
);

create table Vino_has_Sorta(
idVInoSorta int primary key auto_increment not null,
procent decimal
);

create table Prodaja_has_Vino(
idProdajaVino int primary key auto_increment not null,
kolicina int not null
);


alter table Proizvajalec_has_Vino
add foreign key (idProizvajalec) references Proizvajalec(idProizvajalec),
add foreign key (idVino) references Vino(idVino);

alter table Degustacija_has_Vino
add foreign key (idVino) references Vino(idVino),
add foreign key (idDegustacija) references Degustacija(idDegustacija);

alter table Serija
add foreign key (idProizvajalec) references Proizvajalec(idProizvajalec);

alter table Klet_has_Proizvajalec
add foreign key (idKlet) references Klet(idKlet),
add foreign key (idProizvajalec) references Proizvajalec(idProizvajalec);

alter table Klet_has_Vino
add foreign key (idKlet) references Klet(idKlet),
add foreign key (idVino) references Vino(idVino);

alter table Sorta_has_Rajon
add foreign key (idSorta) references Sorta(idSorta),
add foreign key (idRajon) references Rajon(idRajon);

alter table Nakup
add foreign key (idKlet) references Klet(idKlet),
add foreign key (idProizvajalec) references Proizvajalec(idProizvajalec);

alter table Nakup_has_Vino
add foreign key (idNakup) references Nakup(idNakup),
add foreign key (idVino) references Vino(idVino);

alter table Vino
add foreign key (idSerija) references Serija(idSerija);

alter table Serija
add foreign key (idProizvajalec) references Proizvajalec(idProizvajalec);

alter table Prodaja
add foreign key (idKLet) references Klet(idKlet),
add foreign key (idStranka) references Stranka(idStranka);

alter table Vino_has_Sorta
add foreign key (idVino) references Vino(idVino),
add foreign key (idSorta) references Sorta(idSorta);

alter table Prodaja_has_Vino
add foreign key (idVino) references Vino(idVino),
add foreign key (idProdaja) references Prodaja(idProdaja);

insert into Proizvajalec
values ("Proizvajalec1", "Naslov1", "DavcnaX"),
("Proizvajalec2", "Naslov2", "DavcnaZ"),
("Proizvajalec3", "Naslov3", "DavcnaB"),
("Proizvajalec4", "Naslov4", "DavcnaS"),
("Proizvajalec5", "Naslov5", "DavcnaT");

insert into Degustacija
values ("DegustacijaX", TO_DATE("17/12/1999", "DD/MM/YY")),
("Degustacija2", TO_DATE("18/12/1999", "DD/MM/YY")),
("Degustacija15", TO_DATE("19/12/1999", "DD/MM/YY")),
("DegustacijaDFD", TO_DATE("20/12/1999", "DD/MM/YY")),
("Degustacija4434", TO_DATE("21/12/1999", "DD/MM/YY"));
