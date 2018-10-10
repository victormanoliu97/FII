using System;
using System.Collections.Generic;
using System.Text;

namespace Laborator_02.ArchitectData
{
    public class Architect : EmployeeData.Employee
    {
        public Architect(int id, string firstName, string lastName, DateTime startDate, DateTime endDate, int salary) : base(id, firstName, lastName, startDate, endDate, salary)
        {
            
        }
        public override string Salutation()
        {
            return "Hello architect";
        }
    }
}
