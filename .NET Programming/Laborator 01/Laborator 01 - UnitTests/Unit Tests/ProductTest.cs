using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Laborator_01.Product;
using FluentAssertions;

namespace Laborator_01___UnitTests.Unit_Tests
{
    [TestClass]
    public class ProductTest
    {
        private Product createTestProduct()
        {
            return new Product(1, "TV", "Smart", DateTime.Now, new DateTime(2018, 12, 15), 30, 40);
        }

        [TestMethod]
        public void DateShouldNotBeInFuture()
        {
            Product auxProduct = createTestProduct();
            (auxProduct.endDate - auxProduct.StartDate).Should().BeGreaterOrEqualTo(new TimeSpan(DateTime.Now.Millisecond));
        }

        [TestMethod]
        public void VATShouldBeCalculatedCorectlyWhenPriceIs30andVat40()
        {
            Product auxProduct = createTestProduct();
            float resultedVat = auxProduct.computeVat();
            resultedVat.Should().Be(12);
        }

        [TestMethod]
        public void AtributesShouldNotBeNull()
        {
            Product auxProduct = createTestProduct();
            auxProduct.Name.Should().NotBeNullOrEmpty();
            auxProduct.Name.Should().NotBeNullOrEmpty();
            auxProduct.Price.Should().BeGreaterThan(0);
            auxProduct.VAT.Should().BeGreaterThan(0);
        }

        [TestMethod]
        public void AttributesShouldBeOfRightType()
        {
            Product auxProduct = createTestProduct();
            auxProduct.Id.Should().BeOfType(typeof(int));
            auxProduct.Name.Should().BeOfType(typeof(string));
            auxProduct.Description.Should().BeOfType(typeof(string));
        }
    }
}
