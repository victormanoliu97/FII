using System;
using Laborator_03.BookData;
using Laborator_03.Repository;

namespace Laborator_03
{
    class Program
    {
        private static void Main(string[] args)
        {
            BookRepository bookRepository = new BookRepository();
            //bookRepository.RetriveAllBooks();
            bookRepository.RetriveAllBooksGroupedByGenre(Genres.Fiction);
        }
    }
}
