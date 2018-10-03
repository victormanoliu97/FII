using System;
using System.Collections.Generic;
using System.Text;

namespace Laborator_01.EmployeeData
{
    public class Employee
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
            this.endDate = endDate;
            Salary = salary;
        }

        public virtual int Id { get; set; }
        public virtual string FirstName { get; set; }
        public virtual string LastName { get; set; }
        public virtual DateTime StartDate { get; set; }
        public virtual DateTime endDate { get; set; }
        public virtual int Salary { get; set; }

        public virtual string GetFullName()
        {
            string fullName = FirstName + " " + LastName;
            return fullName;
        }

        public virtual bool isActive()
        {
            if(DateTime.Today.Ticks >= StartDate.Ticks && DateTime.Today.Ticks <= endDate.Ticks)
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
