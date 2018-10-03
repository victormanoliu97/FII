using System;
using System.Collections.Generic;
using System.Text;
using Laborator_01.Product;
using FluentAssertions;

namespace Laborator_01___Tests.UnitTests
{
    class ProductTest
    {
        private readonly Product _product;

        private Product createTestProduct()
        {
            return new Product(1, "TV", "Smart", DateTime.Now, new DateTime(2018, 12, 15), 30, 40);
        }

        [CustomAssertion]
        public void DateShouldNotBeInFuture()
        {
            (_product.endDate - _product.StartDate).Should().BeLessOrEqualTo(new TimeSpan(DateTime.Now.Millisecond));
        }

        [CustomAssertion]
        public void VATShouldBeCalculatedCorectlyWhenPriceIs30andVat40()
        {
            Product auxProduct = createTestProduct();
            float resultedVat = _product.computeVat();
            resultedVat.Should().Be(12);
        }

        [CustomAssertion]
        public void AtributesShouldNotBeNull()
        {
            Product auxProduct = createTestProduct();
            auxProduct.Name.Should().NotBeNullOrEmpty();
            auxProduct.Name.Should().NotBeNullOrEmpty();
            auxProduct.Price.Should().BeGreaterThan(0);
            auxProduct.VAT.Should().BeGreaterThan(0);
        }

        [CustomAssertion]
        public void AttributesShouldBeOfRightType()
        {
            Product auxProduct = createTestProduct();
            auxProduct.Id.Should().NotBe(null);
            auxProduct.Id.Should().BeOfType(typeof(int));
            auxProduct.Name.Should().BeOfType(typeof(string));
            auxProduct.Description.Should().BeOfType(typeof(string));
        }
    }
}
