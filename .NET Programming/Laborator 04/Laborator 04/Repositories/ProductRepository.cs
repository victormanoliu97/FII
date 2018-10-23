using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Laborator_04.Management;
using Laborator_04.ProductData;

namespace Laborator_04.Repositories
{
    public class ProductRepository
    {
        public void Create(Product product)
        {
            using (ProductManagement entitiesManagement = new ProductManagement())
            {
                entitiesManagement.Products.Add(product);
                entitiesManagement.SaveChanges();
            }
        }

        public void Update(Product product)
        {
            using (ProductManagement entitiesManagement = new ProductManagement())
            {
                entitiesManagement.Products.Update(product);
                entitiesManagement.SaveChanges();
            }
        }

        public void Delete(int id)
        {
            using (ProductManagement entitiesManagement = new ProductManagement())
            {
                Product productFirst = entitiesManagement.Products.First(p => p.Id == id);
                entitiesManagement.Products.Remove(productFirst);
                entitiesManagement.SaveChanges();
            }
        }

        public Product GetById(int id)
        {
            using (ProductManagement entitiesManagement = new ProductManagement())
            {
                Product productFirst = entitiesManagement.Products.First(p => p.Id == id);
                Console.WriteLine(productFirst);
                return productFirst;
            }
        }

        public IQueryable<Product> GetAll()
        {
            using (ProductManagement entitiesManagement = new ProductManagement())
            {
                foreach (var i in entitiesManagement.Products)
                {
                    Console.WriteLine(i);
                }
                return entitiesManagement.Products;
            }
        }

        public IQueryable<Product> GetProductsByPrice(int price)
        {
            using (ProductManagement entitiesManagement = new ProductManagement())
            {
                IQueryable<Product> products = entitiesManagement.Products.Where(p => p.Price == price);
                foreach (var i in products)
                {
                    Console.WriteLine(i);
                }
                return entitiesManagement.Products.Where(p => p.Price == price);
            }
        }
    }
}
