

#Vino izdano v najmanj serijah
select * from Vino group by naziv;

select naziv, c 
from (select *, count(idVino) as c from Vino group by naziv) as tab
where c = (select min(c) from (select *, count(idVino) as c from Vino group by naziv)as tb);

select * from Prodaja;

#Katera je vasa najboljsa stranka?
select Stranka.naziv, total
from (select idStranka, sum(znesek) as total from Prodaja group by idStranka) as nt
join Stranka on Stranka.idStranka = nt.idStranka
where total = (select max(total) from (select idStranka, sum(znesek) as total from Prodaja group by idStranka) as nnt);

#Katera klet je prodala najvec vina
select Klet.naziv, total
from (select idKlet, sum(znesek) as total from Prodaja group by idKlet) as k
join Klet on Klet.idKlet = k.idKlet
where total = (select max(total) from (select idKlet, sum(znesek) as total from Prodaja group by idKlet) as kk);

#Koliksna je zaloga vina "laski rizling" letnik 1996 prve serije
select Vino.idSerija, Vino.naziv, sum(kolicina) as sumkol
from Klet_has_Vino join Vino on Vino.idVino = Klet_has_Vino.idVino
where Vino.naziv = "laski rizling"
group by Vino.naziv;

#Kateri rajoni imajo sorto "Rebula"
select k.naziv, Rajon.naziv
from (select idRajon, naziv from Sorta_has_Rajon join Sorta on Sorta_has_Rajon.idSorta = Sorta.idSorta where naziv = "Rebula") as k
join Rajon on k.idRajon = Rajon.idRajon;

#Spremeni vsebnost alkohola vina "Braundo" letnik 2011 na 13.5%
update Vino
set alkohol = 13.5
where naziv = "Braundo" and letnik = 2011;
select * from Vino;

#Izbrisi degustacijo "10. obletnica Braundo-ja"
select * from Degustacija;
delete from Degustacija_has_Vino where idDegustacija = (select idDegustacija from Degustacija where naziv = "10. obletnica Braundo-ja");
delete from Degustacija where naziv = "10. obletnica Braundo-ja";
select * from Degustacija;