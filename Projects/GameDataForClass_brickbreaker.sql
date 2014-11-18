DROP TABLE IF EXISTS `entity_player_brickbreaker`;
CREATE TABLE `entity_player_brickbreaker` (
  `player_id` int(10) NOT NULL,
  `name` varchar(25) NOT NULL,
  `date_time` datetime DEFAULT NULL,
  PRIMARY KEY (`player_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
INSERT INTO `entity_player_brickbreaker` VALUES (1,'Privat3memberS',NULL),(2,'Shadynasty',NULL),(3,'L3g1taSSaSS1N',NULL),(4,'NuBSaUc3',NULL),(5,'PR0GAEMUR',NULL),(6,'Sk8tr4L1Fe',NULL),(7,'XCr4ZYjok3RX',NULL),(8,'L3G4LIZ3IT',NULL),(9,'SeismicF4ppuR',NULL),(10,'xX1337_QwikSkopurzxX',NULL);



DROP TABLE IF EXISTS `entity_scores_brickbreaker`;
CREATE TABLE `entity_scores_brickbreaker` (
  `result_id` int(10) NOT NULL,
  `score` int(4) NOT NULL,
  `date_time` datetime DEFAULT NULL,
  PRIMARY KEY (`result_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
INSERT INTO `entity_scores_brickbreaker` VALUES (1,500,'2014-11-16 23:59:00'),(2,450,'2014-11-15 13:36:00'),(3,400,'2014-11-12 00:02:00'),(4,350,'2014-11-13 19:58:00'),(5,300,'2014-11-16 14:06:00'),(6,250,'2014-11-15 17:23:00'),(7,200,'2014-11-14 08:41:00'),(8,150,'2014-11-13 12:30:00'),(9,100,'2014-11-16 09:11:00'),(10,50,'2014-11-16 18:51:00');



DROP TABLE IF EXISTS `xref_player_scores_brickbreaker`;
CREATE TABLE `xref_player_scores_brickbreaker` (
  `xref_id` int(10) NOT NULL,
  `player_id` int(10) DEFAULT NULL,
  `result_id` int(10) DEFAULT NULL,
  PRIMARY KEY (`xref_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
INSERT INTO `xref_player_scores_brickbreaker` VALUES (1,1,5),(2,2,3),(3,3,10),(4,4,2),(5,5,8),(6,6,7),(7,7,6),(8,8,1),(9,9,4),(10,10,9);
