using System;
using Laborator_02.Repository;
using Laborator_02.ProductData;
using Laborator_02.ArchitectData;

namespace Laborator_02
{
    class Program
    {
        static void Main(string[] args)
        {
            ProductRepository productRepository = new ProductRepository();
            productRepository.AddProduct(new Product(4, "PC", "Office", DateTime.Today, new DateTime(2018, 12, 15), 2500, 24));
            productRepository.AddProduct(new Product(5, "Tastatura", "Gaming", DateTime.Today, new DateTime(2019, 12, 14), 800, 24));

            Console.WriteLine("Produsul gasit:");
            Console.WriteLine(productRepository.GetPoductByName("PC"));

            //productRepository.RemoveProductByName("Tastatura");
            productRepository.FindAllProducts();

        }
    }
}
