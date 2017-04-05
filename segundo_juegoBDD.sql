----------------------------------------------------------
--	Base de datos relacional
--	Autor: Daniel Abellán
--
--	Esta base de datos no está muy optimizada ya que no requiere
--	una gran velocidad de acceso.
--
----------------------------------------------------------

-- SELECT'S UTILIZADAS EN EL JUEGO

-- Cargar los obstáculos de un escenario
-- select * from CObstacle where idCScenery == <id>

-- Cargar las puertas de un escenario
-- select * from CGate where currCScenery == <id>

-- SCRIPT DE CREACIÓN DE LA BDD

-- Tabla de escenarios
create table CScenery (
	idCScenery 		int not null primary key,
	nameCScenery 	varchar(45) not null,
	widthCScenery	int not null,
	heightCScenery	int not null
);

-- Puertas
create table CGate (
	idCGate			int not null primary key,
	currCScenery	int not null references CScenery(idCScenery),
	pointCScenery	int not null references CScenery(idCScenery),
	codeCGate		int not null,
	dir				int not null,
	xCGate			int not null,
	yCGate			int not null,
	wCGate			int not null,
	hCGate			int not null
);

-- Obstáculos estáticos
create table CObstacle (
	idObstacle		int not null primary key,
	idCScenery		int not null references CScenery(idCScenery),
	xCGate			int not null,
	yCGate			int not null,
	wCGate			int not null,
	hCGate			int not null
);

-- Obstáculos móviles
create table CMovil (
	idMovil			int not null primary key,
	idCScenery		int not null references CScenery(idCScenery),
	xMovil			int not null,
	yMovil			int not null,
	wMovil			int not null,
	hMovil			int not null
);

-- Escenarios de prueba
-- A
insert into CScenery values(0,"test/A/testGrandeA", 1920, 1080);

insert into CGate values (0, 0, 1, 0, 0, 823, 102, 92, 58);
insert into CGate values (1, 0, 1, 1, 3, 502, 356, 77, 134);
insert into CGate values (2, 0, 1, 2, 1, 822, 673, 88, 70);
insert into CGate values (3, 0, 1, 3, 2, 1256, 422, 57, 101);

-- delete from CGate where currCScenery == 0;

insert into CObstacle values (0, 0, 400, 200, 179, 155);
insert into CObstacle values (1, 0, 400, 356, 100, 135);
insert into CObstacle values (2, 0, 400, 490, 179, 150);
insert into CObstacle values (3, 0, 659, 57, 163, 103);
insert into CObstacle values (4, 0, 822, 57, 92, 44);
insert into CObstacle values (5, 0, 915, 57, 237, 103);
insert into CObstacle values (6, 0, 1257, 223, 161, 468);
insert into CObstacle values (7, 0, 684, 673, 137, 145);
insert into CObstacle values (8, 0, 822, 744, 88, 74);
insert into CObstacle values (9, 0, 910, 673, 240, 145);

insert into CMovil values (0, 0, 780, 340, 32, 32);

-- B
insert into CScenery values(1,"test/B/testGrandeB", 1920, 1080);

insert into CGate values (10, 1, 0, 2, 0, 823, 102, 92, 58);
insert into CGate values (11, 1, 0, 3, 3, 502, 356, 77, 134);
insert into CGate values (12, 1, 0, 0, 1, 822, 673, 88, 70);
insert into CGate values (13, 1, 0, 1, 2, 1256, 422, 57, 101);

insert into CObstacle values (10, 1, 400, 200, 179, 155);
insert into CObstacle values (11, 1, 400, 356, 100, 135);
insert into CObstacle values (12, 1, 400, 490, 179, 150);
insert into CObstacle values (13, 1, 659, 57, 163, 103);
insert into CObstacle values (14, 1, 822, 57, 92, 44);
insert into CObstacle values (15, 1, 915, 57, 237, 103);
insert into CObstacle values (16, 1, 1257, 223, 161, 468);
insert into CObstacle values (17, 1, 684, 673, 137, 145);
insert into CObstacle values (18, 1, 822, 744, 88, 74);
insert into CObstacle values (19, 1, 910, 673, 240, 145);