/myapp
    /css
        style.css
    /js
        script.js
    /partials
        header.php
        footer.php
    /includes
        db.php
        functions.php
    create.php
    read.php
    update.php
    delete.php
    index.php


CREATE DATABASE myappdb;
USE myappdb;

CREATE TABLE users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    email VARCHAR(100) NOT NULL UNIQUE,
    age INT NOT NULL
);


HTTP Methods
GET
POST
PUT
HEAD
DELETE
PATCH
OPTIONS
CONNECT
TRACE