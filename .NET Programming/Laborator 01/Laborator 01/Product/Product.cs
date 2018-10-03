using System;
using System.Collections.Generic;
using System.Text;

namespace Laborator_01.Product
{
    public class Product
    {
        public Product(int id, string name, string description, DateTime startDate, DateTime endDate, int price, double vAT)
        {
            Id = id;
            Name = name;
            Description = description;
            StartDate = startDate;
            this.endDate = endDate;
            Price = price;
            VAT = vAT;
        }

        public int Id { get; set; }
        public string Name { get; set; }
        public string Description { get; set; }
        public DateTime StartDate { get; set; }
        public DateTime endDate { get; set; }
        public int Price { get; set; }
        public double VAT { get; set; }

        public bool isValid()
        {
            if (StartDate == null || endDate == null)
            {
                throw new Exception("You can't have null date");
            }
            if (StartDate > endDate)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        public float computeVat()
        {
            if (VAT == null)
            {
                throw new Exception("You can't have a null VAT");
            }
            return Price * (float)VAT / 100;
        }
    }
}
