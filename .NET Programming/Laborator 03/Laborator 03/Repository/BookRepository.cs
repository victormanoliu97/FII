using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using Laborator_03.BookData;

namespace Laborator_03.Repository
{
    public class BookRepository
    {
        private List<Book> bookList = new List<Book>();
        private IEnumerable<Book> bookEnumerable;

        public BookRepository()
        {
            bookList.Add(new Book(1, "Amintiri din Copilarie", 1980, 50, Genres.NonFiction));
            bookList.Add(new Book(2, "Lost Symbol", 2009, 100, Genres.Fiction));
            bookList.Add(new Book(3, "History of religions", 1980, 200, Genres.Fiction));
            bookList.Add(new Book(4, "David Copperfield", 2005, 400, Genres.Fiction));
            bookList.Add(new Book(5, "Doctor Ox", 1975, 350, Genres.Fiction));
            bookList.Add(new Book(6, "Titanic", 1990, 200, Genres.NonFiction));
            bookList.Add(new Book(7, "Scufita Rosie", 1760, 50, Genres.Fiction));
            bookList.Add(new Book(8, "Alba ca zapada", 1750, 40, Genres.Fiction));
            bookList.Add(new Book(9, "Capra cu 3 iezi", 1880, 30, Genres.Fiction));
            bookList.Add(new Book(10, "Suge-o Andrei", 2014, 80, Genres.NonFiction));

            bookEnumerable = bookList.AsEnumerable();
        }

        public IEnumerable<Book> RetriveAllBooks()
        {
            return from book in bookEnumerable
                   select book;
        }

        public IEnumerable<Book> RetriveAllOrderByYearDescending() => bookEnumerable.OrderByDescending(book => book.Year);

        public IEnumerable<Book> RetriveAllOrderByYearAscending() => bookEnumerable.OrderBy(book => book.Year);

        public IEnumerable<Book> RetriveAllOrderByPriceAscending() => bookEnumerable.OrderBy(book => book.Price);

        public IEnumerable<Book> RetriveAllOrderByPriceDescending() => bookEnumerable.OrderByDescending(book => book.Price);

        public IEnumerable<Book> RetriveAllBooksGroupedByGenre(Genres genreToGroup)
        {
            var booksGroupedByGenre = bookEnumerable.GroupBy(book => book.Genres == genreToGroup)
                .OrderBy(newGroup => newGroup.Key).AsEnumerable();

            List<IGrouping<bool, Book>> booksGroupedByGenresList = booksGroupedByGenre.ToList();

            //Brute force testing
            foreach (var i in booksGroupedByGenresList)
            {
                Console.WriteLine(i.Key);
                foreach (var item in i)
                {
                    Console.WriteLine(item);
                }
            }

            IEnumerable<Book> groups = booksGroupedByGenresList.SelectMany(x => x);
            return groups;
        }
    }
}