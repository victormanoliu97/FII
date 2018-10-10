using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using FluentAssertions;
using Laborator_02.ArchitectData;

namespace Laborator_02_Tests.UnitTests
{
    [TestClass]
    public class ArchitectTest
    {
        private Architect createTestArchitect()
        {
            return new Architect(1, "Ionel", "Popescu", DateTime.Today, new DateTime(2018, 12, 15), 7000);
        }

        [TestMethod]
        public void WhenArhitectCreated_Then_ShouldVerifyAllAtributes()
        {
            Architect auxArchitect = createTestArchitect();
            auxArchitect.Id.Should().NotBe(null);
            auxArchitect.FirstName.Should().Be("Ionel");
            auxArchitect.LastName.Should().Be("Popescu");
            auxArchitect.StartDate.Should().Be(DateTime.Today);
            auxArchitect.EndDate.Should().Be(new DateTime(2018, 12, 15));
        }

        [TestMethod]
        public void WhenArchitectCreated_Then_ShouldReturnFullNameCorectly()
        {
            Architect auxArchitect = createTestArchitect();
            auxArchitect.GetFullName().Should().Be("Ionel Popescu");
        }
    }
}
