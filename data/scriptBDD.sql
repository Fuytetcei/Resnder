
-- -----------------------------------------------------
-- Table `mydb`.`Scenery`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS Scenery (
  idScenery INT NOT NULL UNIQUE,
  dimX INT NULL,
  dimY INT NULL,
  dimH INT NULL,
  dimW INT NULL,
  name VARCHAR(45) NULL UNIQUE,
  PRIMARY KEY (idScenery));


-- -----------------------------------------------------
-- Table `mydb`.`Obstacle`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS Obstacle (
  idObstacle INT NOT NULL UNIQUE,
  Scenery_idScenery INT NOT NULL UNIQUE,
  dimX INT NULL,
  dimY INT NULL,
  dimH INT NULL,
  dimW INT NULL,
  PRIMARY KEY (idObstacle),
  CONSTRAINT fk_Obstacle_Scenery
    FOREIGN KEY (Scenery_idScenery) REFERENCES Scenery (idScenery)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION);


-- -----------------------------------------------------
-- Table `mydb`.`Gate`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS Gate (
  idGate     INT NOT NULL UNIQUE,
  scnName    VARCHAR(45) NULL,
  code       VARCHAR(45) NULL,
  idObstacle INT NOT NULL UNIQUE,
  idScenery  INT NOT NULL UNIQUE,
  dir        INT,
  PRIMARY KEY (idGate),
  CONSTRAINT fk_Gate_Obstacle1
    FOREIGN KEY (idObstacle , idScenery)
    REFERENCES Obstacle (idObstacle, Scenery_idScenery)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION);



-- -----------------------------------------------------
-- INSERTS
-- -----------------------------------------------------

-- TestGrande
insert into Scenery (idScenery, dimH, dimW, name)
values              (00000,     1920, 1080, 'testGrande');
	-- Obstacle
	insert into Obstacle (idObstacle, Scenery_idScenery, dimX, dimY, dimH, dimW)
	values				 (000000, 00000, 287, 328, 58, 400);
	insert into Obstacle (idObstacle, Scenery_idScenery, dimX, dimY, dimH, dimW)
	values				 (000001, 00000, 479, 555, 169, 103);
	insert into Obstacle (idObstacle, Scenery_idScenery, dimX, dimY, dimH, dimW)
	values				 (000002, 00000, 685, 555, 1095, 103);
	insert into Obstacle (idObstacle, Scenery_idScenery, dimX, dimY, dimH, dimW)
	values				 (000003, 00000, 652, 588, 32, 73);

	-- Gate
	insert into Obstacle (idObstacle, Scenery_idScenery, dimX, dimY, dimH, dimW)
	values				 (000004, 00000, 650, 555, 35, 32);
	insert into Gate (idGate, scnName, code,  dir, idObstacle, idScenery)
	values			 (000000, 'Test',  code0, 1,   000004,     00000);

-- Test
insert into Scenery (idScenery, dimH, dimW, name)
values              (00001,     800,  600,  'Test');

	-- Obstacle
	insert into Obstacle (idObstacle, Scenery_idScenery, dimX, dimY, dimH, dimW)
	values				 (000005);
	insert into Obstacle (idObstacle, Scenery_idScenery, dimX, dimY, dimH, dimW)
	values				 (000006);
	insert into Obstacle (idObstacle, Scenery_idScenery, dimX, dimY, dimH, dimW)
	values				 (000007);
	insert into Obstacle (idObstacle, Scenery_idScenery, dimX, dimY, dimH, dimW)
	values				 (000008);
	insert into Obstacle (idObstacle, Scenery_idScenery, dimX, dimY, dimH, dimW)
	values				 (000009);
	insert into Obstacle (idObstacle, Scenery_idScenery, dimX, dimY, dimH, dimW)
	values				 (000010);
	insert into Obstacle (idObstacle, Scenery_idScenery, dimX, dimY, dimH, dimW)
	values				 (000011);
	insert into Obstacle (idObstacle, Scenery_idScenery, dimX, dimY, dimH, dimW)
	values				 (000012);

	--Gate
	insert into Gate (idGate, scnName, code, idObstacle, idScenery)
	values			 ();