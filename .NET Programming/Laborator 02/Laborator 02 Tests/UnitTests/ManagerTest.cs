using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using FluentAssertions;
using Laborator_02.Manager.Data;

namespace Laborator_02_Tests.UnitTests
{
    [TestClass]
    public class ManagerTest
    {
        private Manager createTestManager()
        {
            return new Manager(1, "Ionel", "Popescu", DateTime.Today, new DateTime(2018, 12, 15), 7000);
        }

        [TestMethod]
        public void WhenManagerCreated_Then_ShouldVerifyAllAtributes()
        {
            Manager auxManager = createTestManager();
            auxManager.Id.Should().NotBe(null);
            auxManager.FirstName.Should().Be("Ionel");
            auxManager.LastName.Should().Be("Popescu");
            auxManager.StartDate.Should().Be(DateTime.Today);
            auxManager.EndDate.Should().Be(new DateTime(2018, 12, 15));
        }

        [TestMethod]
        public void WhenManagerCreated_Then_ShouldReturnFullNameCorectly()
        {
            Manager auxManager = createTestManager();
            auxManager.GetFullName().Should().Be("Ionel Popescu");
        }
    }
}
