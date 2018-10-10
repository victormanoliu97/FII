using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using FluentAssertions;
using Laborator_02.Repository;
using Laborator_02.ProductData;

namespace Laborator_02_Tests.UnitTests
{
    [TestClass]
    public class ProductRepositoryTest
    {
        private ProductRepository createTestProductRepository()
        {
            return new ProductRepository();
        }

        [TestMethod]
        public void WhenProductRepositoryCreated_Then_ItShouldHave3Elements()
        {
            ProductRepository auxRepository = createTestProductRepository();
            auxRepository.FindAllProducts().Count.Should().Be(3);
        }

        [TestMethod]
        public void WhenSearchForTVByName_Then_ItShouldHave1ElementMatching()
        {
            ProductRepository auxRepository = createTestProductRepository();
            auxRepository.GetPoductByName("TV").Should().NotBeNull();
            auxRepository.GetPoductByName("TV").Id.Should().Be(1);
            auxRepository.GetPoductByName("TV").Description.Should().Be("TV Smart");
        }

        [TestMethod]
        public void WhenSearchForPhoneByName_Then_ItShouldHave0ElementMatching()
        {
            ProductRepository auxRepository = createTestProductRepository();
            auxRepository.GetPoductByName("Phone").Should().BeNull();
        }

        [TestMethod]
        public void WhenAddNewProduct_ItShouldHave4Elements()
        {
            ProductRepository auxRepository = createTestProductRepository();
            auxRepository.AddProduct(new Product(4, "Test", "Testare", DateTime.Now, new DateTime(2018, 12, 15), 200, 24));
            auxRepository.FindAllProducts().Count.Should().Be(4);
        }

        [TestMethod]
        public void WhenGetProductByPosition1_ItShouldReturnFrigider()
        {
            ProductRepository auxRepository = createTestProductRepository();
            auxRepository.GetProductByPosition(1).Name.Should().Be("Frigider");
        }

        [TestMethod]
        public void WhenGetProductByPosition20_ItShouldReturnNull()
        {
            ProductRepository auxRepository = createTestProductRepository();
            auxRepository.GetProductByPosition(20).Should().BeNull();
        }

        [TestMethod]
        public void WhenRemoveProduct_ItShouldHave2Elements()
        {
            ProductRepository auxRepository = createTestProductRepository();
            auxRepository.RemoveProductByName("Frigider");
            auxRepository.FindAllProducts().Count.Should().Be(2);
        }
    }
}
