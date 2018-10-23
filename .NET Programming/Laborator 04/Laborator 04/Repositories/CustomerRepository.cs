using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Laborator_04.CustomerData;
using Laborator_04.Management;

namespace Laborator_04.Repositories
{
    public class CustomerRepository
    {
        public void Create(Customer customer)
        {
            using (ProductManagement entitiesManagement = new ProductManagement())
            {
                entitiesManagement.Customers.Add(customer);
                entitiesManagement.SaveChanges();
            }
        }

        public void Update(Customer customer)
        {
            using (ProductManagement entitiesManagement = new ProductManagement())
            {
                entitiesManagement.Customers.Update(customer);
                entitiesManagement.SaveChanges();
            }
        }

        public void Delete(int id)
        {
            using (ProductManagement entitiesManagement = new ProductManagement())
            {
                Customer customerFirst = entitiesManagement.Customers.First(c => c.Id == id);
                entitiesManagement.Customers.Remove(customerFirst);
                entitiesManagement.SaveChanges();
            }
        }


        public Customer GetById(int id)
        {
            using (ProductManagement entitiesManagement = new ProductManagement())
            {
                Customer customerFirst = entitiesManagement.Customers.First(c => c.Id == id);
                Console.WriteLine(customerFirst);
                return customerFirst;
            }
        }

        public IQueryable<Customer> GetAll()
        {
            using (ProductManagement entitiesManagement = new ProductManagement())
            {
                foreach (var i in entitiesManagement.Customers)
                {
                    Console.WriteLine(i);
                }
                return entitiesManagement.Customers;
            }
        }

        public IQueryable<Customer> GetCustomerByEmail(string email)
        {
            using (ProductManagement entitiesManagement = new ProductManagement())
            {
                IQueryable<Customer> customers = entitiesManagement.Customers.Where(c => c.CustomerEmail.Equals(email));
                foreach (var i in customers)
                {
                    Console.WriteLine(i);
                }
                return entitiesManagement.Customers.Where(c => c.CustomerEmail == email);
            }
        }

    }
}
