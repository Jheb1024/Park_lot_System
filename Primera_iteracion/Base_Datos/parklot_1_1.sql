-- QUERY PARA CREACION DE BASE DE DATOS --
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
  `nombre_propietario` varchar(40) NOT NULL,
  `numero_tarjeta` varchar(18) NOT NULL,
  `cvc` int(4) NOT NULL,
  `caducidad` int(4) NOT NULL,
  `tipo_tarjeta` varchar(20) NOT NULL,
  `nombre_banco` varchar(20) NOT NULL,
  PRIMARY KEY (`id_tarjeta`)
);


	CREATE TABLE `administrador` (
  `id_administrador` int(11) NOT NULL AUTO_INCREMENT,
  `nombre_admin` varchar(50) NOT NULL,
  `a_paterno` varchar(50) NOT NULL,
  `a_materno` varchar(50) NOT NULL,
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
  `pais` varchar(20) NOT NULL,
  `ciudad` varchar(40) NOT NULL,
  `estado` varchar(40) NOT NULL,
  `calle` varchar(40) NOT NULL,
  `numero_domicilio` varchar(15) NOT NULL,
  `matricula` varchar(15) NOT NULL,
  `tipo_coche` varchar(15) NOT NULL,
  `id_usuario` INT NOT NULL,
  `id_tarjeta` INT NOT NULL,
  primary key(`id_cliente`),
  FOREIGN KEY (`id_usuario`) REFERENCES  `usuario`(`id_usuario`),
  FOREIGN KEY (`id_tarjeta`) REFERENCES  `datos_bancarios`(`id_tarjeta`)
);


-- Insercion de datos ejemplo --

INSERT INTO `usuario` (`nombre_usuario`, `password`, `tipo_usuario`, `estado`)
 VALUES
('admi@gmail.com', '1234','administrador',1),
('john@gmail.com', '1234','clientebasico',1);

INSERT INTO `administrador` (`nombre_admin`, `a_paterno`, `a_materno`,`id_usuario`)
 VALUES
('Marco', 'Martinez','Cruz',1);


INSERT INTO `datos_bancarios` (`nombre_propietario`, `numero_tarjeta`, `cvc`,
`caducidad`,`tipo_tarjeta`,`nombre_banco`)
 VALUES
('John Gomez Agustion', '5599245217453567',855,0324,'Debito','Santander');



INSERT INTO `cliente` (`id_cliente`,`nombre_cliente`,`aPaterno_cliente`,`aMaterno_cliente`,
`correo`,`telefono`,`pais`,`ciudad`,`estado`,`calle`,`numero_domicilio`,`matricula` ,
`tipo_coche`,`id_usuario`,`id_tarjeta`)
 VALUES
('1','John', 'Gomez', 'Agustion', 'john@gmail.com',1234567890,'mexico','cholula','puebla','4 oriente','207','12d05q','camioneta','2','1');


  
  select * from datos_bancarios;

select C.nombre_cliente,T.numero_tarjeta,T.nombre_banco from
cliente as C inner join datos_bancarios as T where C.id_tarjeta = T.id_tarjeta;

