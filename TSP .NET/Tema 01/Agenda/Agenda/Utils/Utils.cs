using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Agenda.Utils
{
    public class Utils
    {
        public int CalculateAge(DateTime birthDate, DateTime nowDate)
        {
            int age = nowDate.Year - birthDate.Year;

            if (nowDate.Month < birthDate.Month || (nowDate.Month == birthDate.Month && nowDate.Day < birthDate.Day))
                age--;

            return age;
        }
    }
}
