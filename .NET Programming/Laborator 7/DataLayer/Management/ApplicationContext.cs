using DataLayer.CityData;
using DataLayer.PoiData;
using Microsoft.EntityFrameworkCore;

namespace DataLayer.Management
{
    public class ApplicationContext : DbContext
    {
        public DbSet<CityData.City> Cities { get; set; }
        public DbSet<PoiData.Poi> Poi { get; set; }

        public ApplicationContext(DbContextOptions options) : base(options)
        {
            Database.EnsureCreated();
        }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            modelBuilder.Entity<City>().Property(c => c.Name).IsRequired().HasMaxLength(100);
            modelBuilder.Entity<City>().Property(c => c.Description).IsRequired().HasMaxLength(150);
            modelBuilder.Entity<Poi>().Property(p => p.Name).IsRequired().HasMaxLength(100);
            modelBuilder.Entity<Poi>().Property(p => p.Description).IsRequired().HasMaxLength(150);
        }
    }
}
