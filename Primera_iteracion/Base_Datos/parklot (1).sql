-- phpMyAdmin SQL Dump
-- version 4.9.1
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 04-09-2020 a las 03:28:29
-- Versión del servidor: 10.4.8-MariaDB
-- Versión de PHP: 7.3.11

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `parklot`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `adminstrador`
--

CREATE TABLE `adminstrador` (
  `id_administrador` int(11) NOT NULL,
  `nombre_admin` varchar(50) NOT NULL,
  `aPaterno_admin` varchar(50) NOT NULL,
  `aMaterno_admin` varchar(50) NOT NULL,
  `contrasena` varchar(20) NOT NULL,
  `usuario_admin` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Volcado de datos para la tabla `adminstrador`
--

INSERT INTO `adminstrador` (`id_administrador`, `nombre_admin`, `aPaterno_admin`, `aMaterno_admin`, `contrasena`, `usuario_admin`) VALUES
(1, 'Alberto', 'Martinez', 'Gonzales', 'password', 'Admin');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `cliente`
--

CREATE TABLE `cliente` (
  `id_cliente` int(11) NOT NULL,
  `nombre_cliente` varchar(50) NOT NULL,
  `aPaterno_cliente` varchar(50) NOT NULL,
  `aMaterno_cliente` varchar(50) NOT NULL,
  `correo` varchar(50) NOT NULL,
  `contrasena` varchar(20) NOT NULL,
  `usuario_cliente` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Volcado de datos para la tabla `cliente`
--

INSERT INTO `cliente` (`id_cliente`, `nombre_cliente`, `aPaterno_cliente`, `aMaterno_cliente`, `correo`, `contrasena`, `usuario_cliente`) VALUES
(1, 'Marco Antonio', 'Martinez', 'Cruz', 'marcocruz@gmail.com', 'password', 'Mark'),
(2, 'Daniel', 'Pérez', 'Montiel', 'dannpm@gmail.com', 'password', 'Dani');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `datosbancarios`
--

CREATE TABLE `datosbancarios` (
  `numero_tarjeta` varchar(16) NOT NULL,
  `cvc` int(4) NOT NULL,
  `tipo_tarjeta` varchar(10) NOT NULL,
  `id_cliente` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Volcado de datos para la tabla `datosbancarios`
--

INSERT INTO `datosbancarios` (`numero_tarjeta`, `cvc`, `tipo_tarjeta`, `id_cliente`) VALUES
('371756483123', 6477, 'Crédito', 1);

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `adminstrador`
--
ALTER TABLE `adminstrador`
  ADD PRIMARY KEY (`id_administrador`);

--
-- Indices de la tabla `cliente`
--
ALTER TABLE `cliente`
  ADD PRIMARY KEY (`id_cliente`);

--
-- Indices de la tabla `datosbancarios`
--
ALTER TABLE `datosbancarios`
  ADD UNIQUE KEY `numero_tarjeta` (`numero_tarjeta`),
  ADD KEY `id_cliente` (`id_cliente`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `adminstrador`
--
ALTER TABLE `adminstrador`
  MODIFY `id_administrador` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT de la tabla `cliente`
--
ALTER TABLE `cliente`
  MODIFY `id_cliente` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- Restricciones para tablas volcadas
--

--
-- Filtros para la tabla `datosbancarios`
--
ALTER TABLE `datosbancarios`
  ADD CONSTRAINT `datosbancarios_ibfk_1` FOREIGN KEY (`id_cliente`) REFERENCES `cliente` (`id_cliente`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
