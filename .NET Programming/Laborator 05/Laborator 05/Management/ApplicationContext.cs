using Microsoft.EntityFrameworkCore;
using Laborator_05.CityData;
using Laborator_05.PoiData;
using DbContext = Microsoft.EntityFrameworkCore.DbContext;

namespace Laborator_05.Management
{
    public class ApplicationContext : DbContext
    {
        public DbSet<City> Cities { get; set; }
        public DbSet<Poi> Pois { get; set; }

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            if (!optionsBuilder.IsConfigured)
            {
                optionsBuilder.UseSqlServer(@"Server=(localdb)\mssqllocaldb;Database=Lab05DB;Trusted_Connection=True;");
            }
        }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            modelBuilder.Entity<City>().ToTable("Cities");
            modelBuilder.Entity<City>(
                c =>
                {
                    c.Property(e => e.CityId);
                    c.Property(e => e.Name);
                    c.Property(e => e.Description);
                    c.Property(e => e.Latitude);
                    c.Property(e => e.Longitude);
                });

            modelBuilder.Entity<Poi>().ToTable("Poi");
            modelBuilder.Entity<Poi>(
                c =>
                {
                    c.Property(e => e.PoiId);
                    c.Property(e => e.Name);
                    c.Property(e => e.Description);
                    c.Property(e => e.CityId);
                });

        }

    }
}
