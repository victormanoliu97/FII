using System;

namespace Laborator_02.Manager.Data
{
    public class Manager : EmployeeData.Employee
    {
        public Manager(int id, string firstName, string lastName, DateTime startDate, DateTime endDate, int salary) : base(id, firstName, lastName, startDate, endDate, salary)
        {

        }

        public override string Salutation()
        {
            return "Hello manager";
        }
    }
}
