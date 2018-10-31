using System.Linq;
using Laborator_05.CityData;
using Laborator_05.Management;

namespace Laborator_05.Repositories
{
    public class CityRepository : ICityRepository
    {
        private ApplicationContext _context;

        public CityRepository(ApplicationContext context)
        {
            _context = context;
        }

        public void CreateCity(City city)
        {
            _context.Cities.Add(city);
            _context.SaveChanges();
        }

        public void RemoveCity(int id)
        {
            City cityFirst = _context.Cities.First(c => c.CityId == id);
            _context.Cities.Remove(cityFirst);
            _context.SaveChanges();
        }

        public IQueryable<City> GetCities()
        {
            return _context.Cities;

        }
    }
}
