using System.Linq;
using Laborator_05.CityData;

namespace Laborator_05.Repositories
{
    public interface ICityRepository
    {
        void CreateCity(City city);
        void RemoveCity(int id);
        IQueryable<City> GetCities();
    }
}
