# diagram-scene

Simple diagram view in C++ created by Qt Creator 4.2.1 based QT 5.8.0 (MSVC 2015, 32 bit)

Entry point to the application: main.cpp

You need to download https://dev.mysql.com/downloads/connector/c/

and put libmysql.dll into your QT installation (in my case, it is C:\Qt\5.8\mingw53_32\bin)

And you need to have a database, qtschema as follows:

/*
SQLyog Community v12.4.0 (64 bit)
MySQL - 10.1.21-MariaDB : Database - qtschema
*********************************************************************
*/


/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;
CREATE DATABASE /*!32312 IF NOT EXISTS*/`qtschema` /*!40100 DEFAULT CHARACTER SET utf8 */;

USE `qtschema`;

/*Table structure for table `users` */

DROP TABLE IF EXISTS `users`;

CREATE TABLE `users` (
  `mail` varchar(50) NOT NULL,
  `name` varchar(20) DEFAULT NULL,
  `surname` varchar(20) DEFAULT NULL,
  `username` varchar(40) DEFAULT NULL,
  `password` varchar(40) DEFAULT NULL,
  `commitList` varchar(255) DEFAULT NULL,
  `history` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`mail`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `users` */

insert  into `users`(`mail`,`name`,`surname`,`username`,`password`,`commitList`,`history`) values 

('barantopal@barantopal.com','baran','topal','baran','1234',NULL,NULL),

('oguzhanablak@gmail.com','oğuzhan','ablak','oguzhan','5678',NULL,NULL);

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

