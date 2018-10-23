CREATE TABLE Products
(
	Id int PRIMARY KEY NOT NULL,
	ProductName varchar(25) NOT NULL,
	ProductDescription varchar(25),
	StartDate datetime not null,
	EndDate datetime not null,
	Price int not null,
	Vat float not null
)
GO

CREATE TABLE Customers
(
	Id int PRIMARY KEY NOT NULL,
	CustomerName varchar(25) NOT NULL,
	CustomerAddress varchar(25) NOT NULL,
	CustomerPhone int NOT NULL,
	CustomerEmail varchar(50) NOT NULL
)
GO