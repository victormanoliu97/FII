using System;
using System.Collections.Generic;
using System.Text;
using Laborator_01.Manager;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using FluentAssertions;

namespace Laborator_01___UnitTests.Unit_Tests
{
    [TestClass]
    public class ManagerTest
    {
        private Manager createTestManager()
        {
            return new Manager(1,"Ionel", "Popescu", DateTime.Today, new DateTime(2018,12,15), 7000);
        }

        [TestMethod]
        public void DateShouldNotBeInFuture()
        {
            Manager auxManager = createTestManager();
            (auxManager.endDate - auxManager.StartDate).Should().BeGreaterOrEqualTo(new TimeSpan(DateTime.Now.Millisecond));
        }

        [TestMethod]
        public void FullNameShouldBeReturnedCorectly()
        {
            Manager auxManager = createTestManager();
            string auxManagerFullName = auxManager.GetFullName();
            auxManagerFullName.Should().Be("Ionel Popescu");
        }

        [TestMethod]
        public void AttributesShouldNotBeNull()
        {
            Manager auxManager = createTestManager();
            auxManager.Id.Should().NotBe(null);
            auxManager.FirstName.Should().NotBeNullOrEmpty();
            auxManager.LastName.Should().NotBeNullOrEmpty();
            auxManager.Salary.Should().BeGreaterThan(0);
        }

        [TestMethod]
        public void AttributesShouldBeOfRightType()
        {
            Manager auxManager = createTestManager();
            auxManager.Id.Should().BeOfType(typeof(int));
            auxManager.FirstName.Should().BeOfType(typeof(string));
            auxManager.LastName.Should().BeOfType(typeof(string));
            auxManager.Salary.Should().BeOfType(typeof(int));
        }
    }
}
