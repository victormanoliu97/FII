using System;
using Laborator_04.CustomerData;
using Laborator_04.ProductData;
using Laborator_04.Repositories;

namespace Laborator_04
{
    class Program
    {
        static void Main(string[] args)
        {
            //ProductRepository productRepository = new ProductRepository();
            //productRepository.Create(new Product(1, "Test", "Test1", new DateTime(2018, 10, 23), new DateTime(2018, 11, 24), 100, 25));
            //productRepository.Create(new Product(2, "Test2", "Test2", new DateTime(2018, 10, 23), new DateTime(2018, 11, 24), 100, 25));
            //productRepository.Create(new Product(3, "Test3", "Test3", new DateTime(2018, 10, 23), new DateTime(2018, 11, 24), 200, 25));

            //productRepository.Update(new Product(1, "Test", "Test2", new DateTime(2018, 10, 23), new DateTime(2018, 11, 24), 100, 25));

            //productRepository.Delete(3);

            //productRepository.GetAll();
            //productRepository.GetProductsByPrice(200);

            CustomerRepository customerRepository = new CustomerRepository();
            //customerRepository.Create(new Customer(2,"Ionela","Str Ceva", 40752094, "ionel@gmail.com"));
            customerRepository.Update(new Customer(1, "Ionel", "Str Ceva", 40752094, "ionelionel@gmail.com"));
        }
    }
}
