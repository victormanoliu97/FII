using System;
using System.Collections.Generic;
using System.Text;

namespace Laborator_04.CustomerData
{
    public class Customer
    {
        public Customer(int id, string customerName, string customerAddress, int customerPhone, string customerEmail)
        {
            Id = id;
            CustomerName = customerName;
            CustomerAddress = customerAddress;
            CustomerPhone = customerPhone;
            CustomerEmail = customerEmail;
        }

        public int Id { get; private set; }
        public string CustomerName { get; private set; }
        public string CustomerAddress { get; private set; }
        public int CustomerPhone { get; private set; }
        public string CustomerEmail { get; private set; }

        public override string ToString()
        {
            return Id + " " + CustomerName + " " + CustomerAddress + " " + CustomerPhone + " " + CustomerEmail;
        }
    }
}
