using System;
using System.Collections.Generic;
using System.Text;
using Laborator_01.EmployeeData;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using FluentAssertions;

namespace Laborator_01___UnitTests.Unit_Tests
{
    [TestClass]
    public class EmployeeTest
    {
        private Employee createTestEmployee()
        {
            return new Employee(1, "Vasile", "John", DateTime.Now, new DateTime(2018, 12, 15), 3000);
        }

        [TestMethod]
        public void DateShouldNotBeInFuture()
        {
            Employee auxEmployee = createTestEmployee();
            (auxEmployee.endDate - auxEmployee.StartDate).Should().BeGreaterOrEqualTo(new TimeSpan(DateTime.Now.Millisecond));
        }

        [TestMethod]
        public void FullNameShouldBeReturnedCorectly()
        {
            Employee auxManager = createTestEmployee();
            string auxEmployeeFullName = auxManager.GetFullName();
            auxEmployeeFullName.Should().Be("Vasile John");
        }

        [TestMethod]
        public void AttributesShouldNotBeNull()
        {
            Employee auxEmployee = createTestEmployee();
            auxEmployee.Id.Should().NotBe(null);
            auxEmployee.FirstName.Should().NotBeNullOrEmpty();
            auxEmployee.LastName.Should().NotBeNullOrEmpty();
            auxEmployee.Salary.Should().BeGreaterThan(0);
        }

        [TestMethod]
        public void AttributesShouldBeOfRightType()
        {
            Employee auxEmployee = createTestEmployee();
            auxEmployee.Id.Should().BeOfType(typeof(int));
            auxEmployee.FirstName.Should().BeOfType(typeof(string));
            auxEmployee.LastName.Should().BeOfType(typeof(string));
            auxEmployee.Salary.Should().BeOfType(typeof(int));
        }

        [TestMethod]
        public void isActiveShouldReturnFalseWhenDatesAreNotToday()
        {
            Employee auxEmployee = new Employee(1, "Danut", "Mariceanu", new DateTime(2019, 12, 15), new DateTime(2019, 12, 17), 2000);
            bool isActive = auxEmployee.isActive();
            isActive.Should().BeFalse();
        }
    }
}
