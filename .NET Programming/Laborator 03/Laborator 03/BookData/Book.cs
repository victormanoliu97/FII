using System;
using System.Collections.Generic;
using System.Text;

namespace Laborator_03.BookData
{
    public class Book
    {
        public Book(int id, string title, int year, int price, Genres genres)
        {
            Id = id;
            Title = title;
            Year = year;
            Price = price;
            Genres = genres;
        }

        public int Id { get; private set; }
        public string Title { get; private set; }
        public int Year { get; private set; }
        public int Price { get; private set; }

        public Genres Genres { get; private set; }

        public override string ToString()
        {
            return Id + " " + Title + " " + Year + " " + Price + " " + Genres;
        }
    }
}
