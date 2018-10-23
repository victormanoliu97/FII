using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Text;

namespace Laborator_04.ProductData
{
    public class Product
    {
        public Product(int id, string productName, string productDescription, DateTime startDate, DateTime endDate, int price, double vAT)
        {
            Id = id;
            ProductName = productName;
            ProductDescription = productDescription;
            StartDate = startDate;
            this.endDate = endDate;
            Price = price;
            VAT = vAT;
        }
        
        public int Id { get; private set; }

        [Required(ErrorMessage = "You need to provide the product name")]
        [StringLength(50)]
        public string ProductName { get; private set; }

        public string ProductDescription { get; private set; }

        [Required(ErrorMessage = "You need to provide the start date")]
        public DateTime StartDate { get; private set; }

        [Required(ErrorMessage = "You need to provide the end date")]
        public DateTime endDate { get; private set; }

        [Required(ErrorMessage = "You need to provide the price")]
        public int Price { get; private set; }

        [Required(ErrorMessage = "You need to provide the VAT")]
        public double VAT { get; private set; }

        public override string ToString()
        {
            return Id + " " + ProductName + " " + ProductDescription + " " + StartDate + " " 
                   + endDate + " " + Price + " " + VAT;
        }
    }
}
