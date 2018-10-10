using System;
using System.Collections.Generic;
using System.Text;

namespace Laborator_02.EmployeeData
{
    public abstract class Employee
    {
        public Employee()
        {

        }
        public Employee(int id, string firstName, string lastName, DateTime startDate, DateTime endDate, int salary)
        {
            Id = id;
            FirstName = firstName;
            LastName = lastName;
            StartDate = startDate;
            EndDate = endDate;
            Salary = salary;
        }

        public virtual int Id { get; set; }
        public virtual string FirstName { get; set; }
        public virtual string LastName { get; set; }
        public virtual DateTime StartDate { get; set; }
        public virtual DateTime EndDate { get; set; }
        public virtual int Salary { get; set; }

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
