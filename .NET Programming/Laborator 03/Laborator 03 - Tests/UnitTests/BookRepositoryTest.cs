using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using FluentAssertions;
using Laborator_03.BookData;
using Laborator_03.Repository;

namespace Laborator_03___Tests.UnitTests
{
    [TestClass]
    public class BookRepositoryTest
    {
        public BookRepository createTestBookRepository()
        {
            return new BookRepository();
        }

        [TestMethod]
        public void When_BookRepositoryCreated_Then_ItShouldHave10Elements()
        {
            createTestBookRepository().RetriveAllBooks().Count().Should().Be(10);
        }

        [TestMethod]
        public void When_RetriveAllOrderByPriceDescending_Then_ItShouldBeCorrectOrder()
        {
            createTestBookRepository().RetriveAllOrderByPriceDescending().Should().BeInDescendingOrder(book => book.Price);
        }

        [TestMethod]
        public void When_RetriveAllOrderByPriceAscending_Then_ItShouldBeCorrectOrder()
        {
            createTestBookRepository().RetriveAllOrderByPriceAscending().Should().BeInAscendingOrder(book => book.Price);
        }

        [TestMethod]
        public void When_RetriveAllOrderByYearDescending_Then_ItShouldBeCorrectOrder()
        {
            createTestBookRepository().RetriveAllOrderByYearDescending().Should().BeInDescendingOrder(book => book.Year);
        }

        [TestMethod]
        public void When_RetriveAllOrderByYearAscending_Then_ItShouldBeCorrectOrder()
        {
            createTestBookRepository().RetriveAllOrderByYearAscending().Should().BeInAscendingOrder(book => book.Year);
        }

        [TestMethod]
        public void When_RetriveAllBooksGroupedByFictionGenre_Then_ItShouldBeGroupedCorectly()
        {
            createTestBookRepository().RetriveAllBooksGroupedByGenre(Genres.Fiction).Take(3).Should().Contain(book => book.Genres == Genres.NonFiction);
            createTestBookRepository().RetriveAllBooksGroupedByGenre(Genres.Fiction).TakeLast(7).Should().Contain(book => book.Genres == Genres.Fiction);
        }
    }
}