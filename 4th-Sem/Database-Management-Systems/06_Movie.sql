create table actor
(
 act_id integer,
 act_name varchar(30),
 act_gender varchar(2),
 primary key(act_id)
 );
create table director
 (
  dir_id integer,
  dir_name varchar(30),
  dir_phone decimal(10),
  primary key(dir_id)
  );
 create table movie
  (mov_id integer, 
  mov_Title varchar(30), 
  mov_Year integer, 
  mov_Lang varchar(20), 
  dir_id integer,
  primary key(mov_id),
  foreign key(dir_id) references director(dir_id)
  ); 
 create table movie_cast 
  (
  act_id integer ,
  mov_id integer, 
  role varchar(15),
  primary key(act_id,mov_id),
  foreign key(act_id)references actor(act_id),
  foreign key(mov_id)references movie(mov_id)
  ); 
create table rating 
  (
  mov_id integer, 
  rev_Stars integer,
  primary key(mov_id),
  foreign key(mov_id)references movie(mov_id)
  );
INSERT INTO ACTOR VALUES (301,'ANUSHKA','F'); 
INSERT INTO ACTOR VALUES (302,'PRABHAS','M'); 
INSERT INTO ACTOR VALUES (303,'PUNITH','M'); 
INSERT INTO ACTOR VALUES (304,'JERMY','M'); 

select * from actor;

INSERT INTO DIRECTOR VALUES (60,'RAJAMOULI', 8751611001); 
INSERT INTO DIRECTOR VALUES (61,'HITCHCOCK', 7766138911); 
INSERT INTO DIRECTOR VALUES (62,'FARAN', 9986776531); 
INSERT INTO DIRECTOR VALUES (63,'STEVEN SPIELBERG', 8989776530); 

select * from director;

INSERT INTO MOVIE VALUES (1001,'BAHUBALI-2', 2017, 'TELAGU', 60); 
INSERT INTO MOVIE VALUES (1002,'BAHUBALI-1', 2015, 'TELAGU', 60); 
INSERT INTO MOVIE VALUES (1003,'AKASH', 2008, 'KANNADA', 61); 
INSERT INTO MOVIE VALUES (1004,'WAR HORSE', 2011, 'ENGLISH', 63); 

select * from movie;

INSERT INTO MOVIE_CAST VALUES (301, 1002, 'HEROINE'); 
INSERT INTO MOVIE_CAST VALUES (301, 1001, 'HEROINE'); 
INSERT INTO MOVIE_CAST VALUES (303, 1003, 'HERO'); 
INSERT INTO MOVIE_CAST VALUES (303, 1002, 'GUEST'); 
INSERT INTO MOVIE_CAST VALUES (304, 1004, 'HERO'); 

select * from movie_cast;

INSERT INTO RATING VALUES (1001, 4); 
INSERT INTO RATING VALUES (1002, 2);
INSERT INTO RATING VALUES (1003, 5); 
INSERT INTO RATING VALUES (1004, 4);

select * from rating;
/* 1. List the titles of all movies directed by ‘Hitchcock’. */
select mov_title from movie where dir_id in
 (select dir_id from director where dir_name='Hitchcock');

/*. Find the movie names where one or more actors acted in two or more movies */
select mov_title from movie m, movie_cast mv where m.mov_id=mv.mov_id and act_id in( select act_id from movie_cast group by act_id having count( act_id)>1) group by mov_title having count(*)>1;

/*List all actors who acted in a movie before 2000 and also in a movie after */
select act_name from actor a join movie_cast c on a.act_id=c.act_id join movie m on c.mov_id=m.mov_id where m.mov_year not between 2000 and 2015;

/*4. Find the title of movies and number of stars for each movie that has at least one rating and find the highest number of stars that movie received. Sort the result by movie title. */
select mov_title ,max(rev_stars) from movie inner join rating using(mov_id) group by mov_title having max(rev_stars)>0 order by mov_title;

/*Update rating of all movies directed by ‘Steven Spielberg’ to 5. */
update rating
set rev_stars=5 where mov_id
in(select mov_id from movie where dir_id
in(select dir_id from director where dir_name='Steven Spielberg'));
