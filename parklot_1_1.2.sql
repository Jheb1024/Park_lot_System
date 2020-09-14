DROP DATABASE IF EXISTS  park_lot_system_db;
CREATE DATABASE park_lot_system_db;
show databases;

use park_lot_system_db;

-- Creacion de tablas que sirven como llaves foraneas --
CREATE TABLE `usuario`(
	`id_usuario` int not null auto_increment,
    `nombre_usuario` nvarchar(50) not null,
    `password` nvarchar(30) not null,
    `tipo_usuario` nvarchar(50) not null,
    `estado` tinyint(1),
    PRIMARY KEY (`id_usuario`));
    
    
    
	CREATE TABLE `datos_bancarios` (
  `id_tarjeta` INT NOT NULL AUTO_INCREMENT,
  `numero_tarjeta` varchar(30) NOT NULL,
  `cvc` int(4) NOT NULL,
  `caducidad` int(6) NOT NULL,
  `tipo_tarjeta` varchar(20) NOT NULL,
  PRIMARY KEY (`id_tarjeta`)
);


	CREATE TABLE `administrador` (
  `id_administrador` int(11) NOT NULL AUTO_INCREMENT,
  `id_usuario` INT NOT NULL,
  PRIMARY KEY (`id_administrador`),
  FOREIGN KEY (`id_usuario`) REFERENCES  `usuario`(`id_usuario`)
);


CREATE TABLE `cliente` (
  `id_cliente` int(11) NOT NULL AUTO_INCREMENT,
  `nombre_cliente` varchar(50) NOT NULL,
  `aPaterno_cliente` varchar(50) NOT NULL,
  `aMaterno_cliente` varchar(50) NOT NULL,
  `correo` varchar(50) NOT NULL,
  `telefono` varchar(15) NOT NULL,
  `calle` varchar(40) NOT NULL,
  `numero_domicilio` varchar(15) NOT NULL,
  `id_usuario` INT NOT NULL,
  `id_tarjeta` INT NOT NULL,
  primary key(`id_cliente`),
  FOREIGN KEY (`id_usuario`) REFERENCES  `usuario`(`id_usuario`),
  FOREIGN KEY (`id_tarjeta`) REFERENCES  `datos_bancarios`(`id_tarjeta`)
);

CREATE TABLE `auto` (
  `id_auto` int not null auto_increment,
  `matricula` nvarchar(40) NOT NULL,
  `tipo_de_coche` nvarchar(40) NOT NULL,
  `id_cliente` int(11) ,
  PRIMARY KEY (`id_auto`),
  FOREIGN KEY (`id_cliente`) REFERENCES  `cliente`(`id_cliente`)
);

CREATE TABLE `suscripción` (
  `id_suscripción` int not null auto_increment,
  `fecha_inicio` DATE NOT NULL,
  `fecha_fin` DATE NOT NULL,
  `renovacio_auto` tinyint(1) NOT NULL,
  `id_cliente` int(11) not null ,
  PRIMARY KEY (`id_suscripción`),
  FOREIGN KEY (`id_cliente`) REFERENCES  `cliente`(`id_cliente`)
);

CREATE TABLE `piso` (
  `id_piso` int not null auto_increment,
  `num_cajones` int not null,
  `id_administrador` int(11) not null ,
  PRIMARY KEY (`id_piso`),
  FOREIGN KEY (`id_administrador`) REFERENCES  `administrador`(`id_administrador`)
);

CREATE TABLE `reservacion` (
  `id_reservacion` int not null auto_increment,
  `fecha` date not null,
  `h_entrada` time not null,
  `h_salida` time not null,
  `num_cajones` int not null,
  `num_dias` int,
  `fecha_inicio` date,
  `fecha_fin` date,
  `id_cliente` int(11) not null,
  PRIMARY KEY (`id_reservacion`),
  FOREIGN KEY (`id_cliente`) REFERENCES  `cliente`(`id_cliente`)
);

CREATE TABLE `cajon` (
  `num_cajone` int not null auto_increment,
  `num_dias` int not null,
  `estado` nvarchar(45) NOT NULL,
  `enetrada` time,
  `salida` time,
  `id_piso` int not null,
   `id_reservacion` int not null,
  PRIMARY KEY (`num_cajone`),
  FOREIGN KEY (`id_piso`) REFERENCES  `piso`(`id_piso`),
  FOREIGN KEY (`id_reservacion`) REFERENCES  `reservacion`(`id_reservacion`)
);

CREATE TABLE `factura` (
  `id_factura` int not null auto_increment,
  `pago` int not null,
  `id_reservacion` int not null,
  PRIMARY KEY (`id_factura`),
  FOREIGN KEY (`id_reservacion`) REFERENCES  `reservacion`(`id_reservacion`)
);


describe usuario;


INSERT INTO `usuario` (`nombre_usuario`, `password`, `tipo_usuario`, `estado`)
 VALUES
('admi@gmail.com', '1234','administrador',1),
('john@gmail.com', '1234','clientebasico',1);



INSERT INTO `administrador` (`id_usuario`)
 VALUES
(1);



describe datos_bancarios;

INSERT INTO `datos_bancarios` (`numero_tarjeta`, `cvc`,
`caducidad`,`tipo_tarjeta`)
 VALUES
('5599245217453567',855,0324,'Debito');


describe cliente;

INSERT INTO `cliente` (`nombre_cliente`,`aPaterno_cliente`,`aMaterno_cliente`,
`correo`,`telefono`,`calle`,`numero_domicilio`,`id_usuario`,`id_tarjeta`)
 VALUES
('John', 'Gomez', 'Agustion', 'john@gmail.com',1234567890,'4 oriente','207','2','1');


describe auto;

INSERT INTO auto(matricula,tipo_de_coche,id_cliente) values('XXXX XX','Camioneta',1);













