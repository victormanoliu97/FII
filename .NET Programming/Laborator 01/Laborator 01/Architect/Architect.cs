using System;
using System.Collections.Generic;
using System.Text;
using Laborator_01.EmployeeData;

namespace Laborator_01.Architect
{
    public class Architect : Employee
    {
        public Architect(int id, string firstName, string lastName, DateTime startDate, DateTime endDate, int salary)
        {
            Id = id;
            FirstName = firstName;
            LastName = lastName;
            StartDate = startDate;
            this.endDate = endDate;
            Salary = salary;
        }

        public override int Id { get; set; }
        public override string FirstName { get; set; }
        public override string LastName { get; set; }
        public override DateTime StartDate { get; set; }
        public override DateTime endDate { get; set; }
        public override int Salary { get; set; }

        public override string GetFullName()
        {
            string fullName = FirstName + " " + LastName;
            return fullName;
        }

        public override bool isActive()
        {
            if (DateTime.Today.Ticks >= StartDate.Ticks && DateTime.Today.Ticks <= endDate.Ticks)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}
