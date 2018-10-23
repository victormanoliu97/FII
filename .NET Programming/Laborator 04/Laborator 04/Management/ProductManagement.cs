using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Text;
using Laborator_04.CustomerData;
using Laborator_04.ProductData;
using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Metadata;
using DbContext = Microsoft.EntityFrameworkCore.DbContext;

namespace Laborator_04.Management
{
    class ProductManagement : DbContext
    {
        public Microsoft.EntityFrameworkCore.DbSet<Product> Products { get; set; }
        public Microsoft.EntityFrameworkCore.DbSet<Customer> Customers { get; set; }

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            if (!optionsBuilder.IsConfigured)
            {
                optionsBuilder.UseSqlServer(@"Server=(localdb)\mssqllocaldb;Database=Lab04DB;Trusted_Connection=True;");
            }
        }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            modelBuilder.Entity<Product>().ToTable("Products");
            modelBuilder.Entity<Product>(
                p =>
                {
                    p.Property(e => e.Id);
                    p.Property(e => e.ProductName);
                    p.Property(e => e.ProductDescription);
                    p.Property(e => e.StartDate);
                    p.Property(e => e.endDate);
                    p.Property(e => e.Price);
                    p.Property(e => e.VAT);

                });

            modelBuilder.Entity<Customer>().ToTable("Customers");
            modelBuilder.Entity<Customer>(
                c =>
                {
                    c.Property(f => f.Id);
                    c.Property(f => f.CustomerName);
                    c.Property(f => f.CustomerAddress);
                    c.Property(f => f.CustomerPhone);
                    c.Property(f => f.CustomerEmail);
                });

            modelBuilder.Entity<Customer>().Property(c => c.CustomerName).IsRequired().HasMaxLength(100);
            modelBuilder.Entity<Customer>().Property(c => c.CustomerAddress).IsRequired().HasMaxLength(300);
            modelBuilder.Entity<Customer>().Property(c => c.CustomerPhone).IsRequired();
        }
    }
}
