using System.Collections.Generic;
using System.Linq;
using DataLayer.CityData;
using DataLayer.Management;

namespace BusinessLayer.Repository
{
    public class CityRepository : ICityRepository
    {
        private readonly ApplicationContext _context;

        public CityRepository(ApplicationContext context)
        {
            _context = context;
        }

        public void CreateCity(City city)
        {
            _context.Cities.Add(city);
            _context.SaveChanges();
        }

        public bool CheckCity(int id)
        {
            var cityFirst = _context.Cities.First(c => c.CityId == id);
            if (cityFirst == null)
            {
                return false;
            }

            return true;
        }

        public void RemoveCity(int id)
        {
            var cityFirst = _context.Cities.First(c => c.CityId == id);
            _context.Cities.Remove(cityFirst);
            _context.SaveChanges();
        }

        public void EditCity(int id, City city)
        {
            var dbCity = _context.Cities.First(c => c.CityId == id);
            dbCity.CityId = city.CityId;
            dbCity.Name = city.Name;
            dbCity.Description = city.Description;
            dbCity.Latitude = city.Latitude;
            dbCity.Longitude = city.Longitude;
            _context.SaveChanges();
        }

        public City GetCity(int id)
        {
            var cityFirst = _context.Cities.First(c => c.CityId == id);
            return cityFirst;
        }

        public List<City> GetCities()
        {
            return _context.Cities.ToList();
        }
    }
}
