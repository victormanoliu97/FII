using System;
using System.Collections.Generic;
using System.Text;
using Laborator_02.ProductData;

namespace Laborator_02.Repository
{
    public class ProductRepository
    {
        private List<Product> productList = new List<Product>();

        public ProductRepository()
        {
            productList.Add(new Product(1, "TV", "TV Smart", DateTime.Today, new DateTime(2018, 12, 15), 3000, 24));
            productList.Add(new Product(2, "Frigider", "Frigider Smecher", DateTime.Today, new DateTime(2018, 11, 24), 2000, 24));
            productList.Add(new Product(3, "Laptop Gaming", "Laptop pentru gameri", DateTime.Today, new DateTime(2019, 10, 24), 5000, 24));
        }

        public Product GetPoductByName(string productName)
        {
            Product resultProduct = null;
            foreach(Product product in productList)
            {
                if(product.Name.Equals(productName))
                {
                    resultProduct = product;
                }
            }
            return resultProduct;
        }

        public List<Product> FindAllProducts()
        {
            foreach(Product product in productList)
            {
                Console.Write(product);
            }
            return productList;
        }

        public void AddProduct(Product product)
        {
            productList.Add(product);
        }

        public void RemoveProductByName(string productName)
        {
            foreach(Product product in productList)
            {
                if(product.Name.Equals(productName))
                {
                    productList.Remove(product);
                }
            }
        }

        public Product GetProductByPosition(int position)
        {
            Product foundProduct = null;
            for(int i=0; i<productList.Count; i++)
            {
                if(position == i)
                {
                    foundProduct = productList[i];
                }
            }
            return foundProduct;
        }

    }
}
