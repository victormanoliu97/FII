using System;
using System.Collections.Generic;
using System.Text;

namespace Laborator_02.EmployeeData
{
    public abstract class Employee
    {
        public Employee(int id, string firstName, string lastName, DateTime startDate, DateTime endDate, int salary)
        {
            Id = id;
            FirstName = firstName;
            LastName = lastName;
            StartDate = startDate;
            EndDate = endDate;
            Salary = salary;
        }

        public int Id { get;private set; }
        public string FirstName { get; private set; }
        public string LastName { get; private set; }
        public DateTime StartDate { get; private set; }
        public DateTime EndDate { get; private set; }
        public int Salary { get; private set;}

        public string GetFullName()
        {
            string fullName = FirstName + " " + LastName;
            return fullName;
        }

        public bool IsActive()
        {
            if (DateTime.Today.Ticks >= StartDate.Ticks && DateTime.Today.Ticks <= EndDate.Ticks)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        public abstract string Salutation();
    }
}
