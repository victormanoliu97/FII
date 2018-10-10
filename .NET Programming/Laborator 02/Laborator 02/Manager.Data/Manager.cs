using System;
using System.Collections.Generic;
using System.Text;

namespace Laborator_02.Manager.Data
{
    public class Manager : EmployeeData.Employee
    {
        public Manager(int id, string firstName, string lastName, DateTime startDate, DateTime endDate, int salary)
        {
            Id = id;
            FirstName = firstName;
            LastName = lastName;
            StartDate = startDate;
            EndDate = endDate;
            Salary = salary;
        }

        public override int Id { get; set; }
        public override string FirstName { get; set; }
        public override string LastName { get; set; }
        public override DateTime StartDate { get; set; }
        public override DateTime EndDate { get; set; }
        public override int Salary { get; set; }

        public override string Salutation()
        {
            return "Hello manager";
        }
    }
}
