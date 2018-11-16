using System.Collections.Generic;
using DataLayer.CityData;

namespace BusinessLayer.Repository
{
    public interface ICityRepository
    {
        void CreateCity(City city);
        bool CheckCity(int id);
        void RemoveCity(int id);
        void EditCity(int id, City city);
        City GetCity(int id);
        List<City> GetCities();
    }
}
