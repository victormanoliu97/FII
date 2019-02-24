using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Agenda
{
    [Serializable]
    public class Contact
    {
        public Contact(string firstName, string lastName, string email, string description, DateTime dateOfBirth, int age)
        {
            FirstName = firstName;
            LastName = lastName;
            Email = email;
            Description = description;
            DateOfBirth = dateOfBirth;
            Age = age;
        }

        public String FirstName { get; set; }
        public String LastName { get; set; }
        public String Email { get; set; }
        public String Description { get; set; }
        public DateTime DateOfBirth { get; set; }
        public int Age { get; set; }

        public override String ToString()
        {
            return FirstName + " " + LastName + " " + Email + " " + Description + " " + DateOfBirth + " " +
                Age;
        }

        public String GetFullName()
        {
            return FirstName + " " + LastName;
        }
    }
}
