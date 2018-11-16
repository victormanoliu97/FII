CREATE TABLE [dbo].[Cities] (
    [CityId]      INT           NOT NULL,
    [Name]        VARCHAR (100) NOT NULL,
    [Description] VARCHAR (150) NOT NULL,
    [Latitude]    FLOAT (53)    NULL,
    [Longitude]   FLOAT (53)    NULL,
    PRIMARY KEY CLUSTERED ([CityId] ASC)
);

CREATE TABLE [dbo].[Poi] (
    [PoiId]       INT           NOT NULL,
    [Name]        VARCHAR (100) NOT NULL,
    [Description] VARCHAR (150) NOT NULL,
    [CityId]      INT           NOT NULL,
    PRIMARY KEY CLUSTERED ([PoiId] ASC),
    FOREIGN KEY ([CityId]) REFERENCES [dbo].[Cities] ([CityId])
);
